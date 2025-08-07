#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../include/inventory.h"
#include "../include/database.h"

// Function prototypes for main
void DisplayMenu();
void DisplayHeader();
void ClearScreen();
void PressAnyKey();
int GetValidInteger(char prompt[]);
float GetValidFloat(char prompt[]);
void GetValidString(char prompt[], char str[], int maxLen);

int main()
{
    PNODE head = NULL;
    int choice, id, quantity, threshold;
    char name[30], filename[100];
    float price;
    
    // Load existing data if available
    printf("Loading existing inventory data...\n");
    LoadInventoryFromFile(&head, "inventory.csv");
    
    DisplayHeader();
    
    do
    {
        DisplayMenu();
        choice = GetValidInteger("Enter your choice");
        
        switch (choice)
        {
        case 1: // Add Item
            ClearScreen();
            printf("[ADD NEW ITEM]\n");
            printf("==============\n");
            
            id = GetValidInteger("Enter Item ID");
            GetValidString("Enter Item Name", name, sizeof(name));
            quantity = GetValidInteger("Enter Quantity");
            price = GetValidFloat("Enter Price (Rs)");
            
            AddItem(&head, id, name, quantity, price);
            PressAnyKey();
            break;
            
        case 2: // Display Inventory
            ClearScreen();
            DisplayInventory(head);
            printf("\nTotal Items: %d\n", CountItems(head));
            printf("Total Inventory Value: Rs%.2f\n", CalculateTotalValue(head));
            PressAnyKey();
            break;
            
        case 3: // Search by ID
            ClearScreen();
            printf("[SEARCH BY ID]\n");
            printf("==============\n");
            
            id = GetValidInteger("Enter Item ID to search");
            PNODE found = SearchByID(head, id);
            if (found != NULL)
            {
                printf("\n[SUCCESS] Item Found:\n");
                printf("ID: %d | Name: %s | Quantity: %d | Price: Rs%.2f\n",
                       found->id, found->name, found->quantity, found->price);
            }
            else
            {
                printf("[ERROR] Item with ID %d not found!\n", id);
            }
            PressAnyKey();
            break;
            
        case 4: // Search by Name
            ClearScreen();
            printf("[SEARCH BY NAME]\n");
            printf("================\n");
            
            GetValidString("Enter Item Name to search", name, sizeof(name));
            found = SearchByName(head, name);
            if (found != NULL)
            {
                printf("\n[SUCCESS] Item Found:\n");
                printf("ID: %d | Name: %s | Quantity: %d | Price: Rs%.2f\n",
                       found->id, found->name, found->quantity, found->price);
            }
            else
            {
                printf("[ERROR] Item '%s' not found!\n", name);
            }
            PressAnyKey();
            break;
            
        case 5: // Update Item
            ClearScreen();
            printf("[UPDATE ITEM]\n");
            printf("=============\n");
            
            id = GetValidInteger("Enter Item ID to update");
            UpdateItem(head, id);
            PressAnyKey();
            break;
            
        case 6: // Delete Item
            ClearScreen();
            printf("[DELETE ITEM]\n");
            printf("=============\n");
            
            id = GetValidInteger("Enter Item ID to delete");
            DeleteItem(&head, id);
            PressAnyKey();
            break;
            
        case 7: // Low Stock Alert
            ClearScreen();
            threshold = GetValidInteger("Enter low stock threshold");
            DisplayLowStock(head, threshold);
            PressAnyKey();
            break;
            
        case 8: // Sort by Price
            ClearScreen();
            printf("[SORTING INVENTORY]\n");
            printf("==================\n");
            SortInventoryByPrice(&head);
            DisplayInventory(head);
            PressAnyKey();
            break;
            
        case 9: // Save to File
            ClearScreen();
            printf("[SAVE INVENTORY]\n");
            printf("===============\n");
            GetValidString("Enter filename (with .csv extension)", filename, sizeof(filename));
            SaveInventoryToFile(head, filename);
            PressAnyKey();
            break;
            
        case 10: // Load from File
            ClearScreen();
            printf("[LOAD INVENTORY]\n");
            printf("===============\n");
            printf("WARNING: This will replace current inventory data.\n");
            printf("Type 'y' to continue or 'n' to cancel: ");
            
            char confirm;
            scanf(" %c", &confirm); // Note the space before %c to skip whitespace
            
            if (confirm == 'y' || confirm == 'Y') {
                FreeInventory(&head); // Clear existing inventory
                printf("Current inventory cleared.\n");
                GetValidString("Enter filename to load", filename, sizeof(filename));
                LoadInventoryFromFile(&head, filename);
            } else {
                printf("Load operation cancelled.\n");
            }
            PressAnyKey();
            break;
            
        case 11: // Create Backup
            ClearScreen();
            printf("[CREATING BACKUP]\n");
            printf("================\n");
            CreateBackup(head);
            PressAnyKey();
            break;
            
        case 12: // Export to CSV
            ClearScreen();
            printf("[EXPORT TO CSV]\n");
            printf("==============\n");
            GetValidString("Enter export filename", filename, sizeof(filename));
            ExportToCSV(head, filename);
            PressAnyKey();
            break;
            
        case 13: // Statistics
            ClearScreen();
            printf("[INVENTORY STATISTICS]\n");
            printf("=====================\n");
            printf("Total Items: %d\n", CountItems(head));
            printf("Total Value: Rs%.2f\n", CalculateTotalValue(head));
            
            // Find most expensive item
            PNODE temp = head;
            PNODE mostExpensive = head;
            while (temp != NULL)
            {
                if (temp->price > mostExpensive->price)
                    mostExpensive = temp;
                temp = temp->next;
            }
            if (mostExpensive != NULL)
                printf("Most Expensive: %s (Rs%.2f)\n", mostExpensive->name, mostExpensive->price);
            
            PressAnyKey();
            break;
            
        case 0: // Exit
            ClearScreen();
            printf("Saving inventory before exit...\n");
            SaveInventoryToFile(head, "inventory.csv");
            printf("Cleaning up memory...\n");
            FreeInventory(&head);
            printf("\nThank you for using Inventory Management System!\n");
            printf("Goodbye!\n");
            break;
            
        default:
            printf("[ERROR] Invalid choice! Please try again.\n");
            PressAnyKey();
        }
        
    } while (choice != 0);
    
    return 0;
}

void DisplayHeader()
{
    ClearScreen();
    printf("+==================================================================+\n");
    printf("|                  INVENTORY MANAGEMENT SYSTEM                    |\n");
    printf("|                         Version 2.0                             |\n");
    printf("|                    Developed in C Language                      |\n");
    printf("+==================================================================+\n\n");
    printf("Welcome to the Advanced Inventory Management System!\n");
    printf("This system helps you manage your inventory efficiently.\n\n");
    PressAnyKey();
}

void DisplayMenu()
{
    ClearScreen();
    printf("+==================================================================+\n");
    printf("|                        MAIN MENU                                |\n");
    printf("+==================================================================+\n");
    printf("|  [INVENTORY OPERATIONS]                                         |\n");
    printf("|     1. Add New Item                                             |\n");
    printf("|     2. Display All Items                                        |\n");
    printf("|     3. Search by ID                                             |\n");
    printf("|     4. Search by Name                                           |\n");
    printf("|     5. Update Item                                              |\n");
    printf("|     6. Delete Item                                              |\n");
    printf("|                                                                 |\n");
    printf("|  [ANALYSIS & REPORTS]                                           |\n");
    printf("|     7. Low Stock Alert                                          |\n");
    printf("|     8. Sort by Price                                            |\n");
    printf("|    13. View Statistics                                          |\n");
    printf("|                                                                 |\n");
    printf("|  [FILE OPERATIONS]                                              |\n");
    printf("|     9. Save to File                                             |\n");
    printf("|    10. Load from File                                           |\n");
    printf("|    11. Create Backup                                            |\n");
    printf("|    12. Export to CSV                                            |\n");
    printf("|                                                                 |\n");
    printf("|     0. Exit Program                                             |\n");
    printf("+==================================================================+\n");
}

void ClearScreen()
{
    system("cls");
}

void PressAnyKey()
{
    printf("\nPress any key to continue...");
    getch();
}

int GetValidInteger(char prompt[])
{
    int value;
    printf("%s: ", prompt);
    while (scanf("%d", &value) != 1)
    {
        printf("[ERROR] Invalid input! Please enter a valid number.\n");
        printf("%s: ", prompt);
        while (getchar() != '\n'); // Clear input buffer
    }
    return value;
}

float GetValidFloat(char prompt[])
{
    float value;
    printf("%s: ", prompt);
    while (scanf("%f", &value) != 1 || value < 0)
    {
        printf("[ERROR] Invalid input! Please enter a valid positive number.\n");
        printf("%s: ", prompt);
        while (getchar() != '\n'); // Clear input buffer
    }
    return value;
}

void GetValidString(char prompt[], char str[], int maxLen)
{
    printf("%s: ", prompt);
    getchar(); // Consume any leftover newline
    fgets(str, maxLen, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
    
    while (strlen(str) == 0)
    {
        printf("[ERROR] Input cannot be empty! Please try again.\n");
        printf("%s: ", prompt);
        fgets(str, maxLen, stdin);
        str[strcspn(str, "\n")] = 0;
    }
}
