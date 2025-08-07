#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/inventory.h"

void AddItem(PPNODE head, int id, char name[], int qty, float price)
{
    // Check if item with same ID already exists
    if (SearchByID(*head, id) != NULL)
    {
        printf("[ERROR] Item with ID %d already exists!\n", id);
        return;
    }

    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if (newn == NULL)
    {
        printf("[ERROR] Memory allocation failed!\n");
        return;
    }

    newn->id = id;
    newn->quantity = qty;
    newn->price = price;
    strcpy(newn->name, name);
    newn->next = NULL;

    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    printf("[SUCCESS] Item '%s' added successfully!\n", name);
}

void AddItemSilent(PPNODE head, int id, char name[], int qty, float price)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if (newn == NULL)
    {
        return; // Silent failure
    }

    newn->id = id;
    newn->quantity = qty;
    newn->price = price;
    strcpy(newn->name, name);
    newn->next = NULL;

    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DisplayInventory(PNODE head)
{
    if (head == NULL)
    {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\n+=================================================================+\n");
    printf("|                        CURRENT INVENTORY                        |\n");
    printf("+=================================================================+\n");
    printf("| ID   | Name                | Quantity | Price (Rs) | Total (Rs) |\n");
    printf("+================================================================+\n");
    
    while (head != NULL)
    {
        float total = head->quantity * head->price;
        printf("| %-4d | %-19s | %-8d | %-10.2f | %-10.2f |\n",
               head->id, head->name, head->quantity, head->price, total);
        head = head->next;
    }
    printf("+================================================================+\n");
}

int CountItems(PNODE head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void DeleteItem(PPNODE head, int id)
{
    if (*head == NULL)
    {
        printf("[ERROR] Inventory is empty!\n");
        return;
    }

    PNODE temp = *head;
    PNODE prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->id == id)
    {
        *head = temp->next;
        printf("[SUCCESS] Item '%s' (ID: %d) deleted successfully!\n", temp->name, temp->id);
        free(temp);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("[ERROR] Item with ID %d not found!\n", id);
        return;
    }

    prev->next = temp->next;
    printf("[SUCCESS] Item '%s' (ID: %d) deleted successfully!\n", temp->name, temp->id);
    free(temp);
}

void UpdateItem(PNODE head, int id)
{
    PNODE item = SearchByID(head, id);
    if (item == NULL)
    {
        printf("[ERROR] Item with ID %d not found!\n", id);
        return;
    }

    int choice;
    printf("\nWhat would you like to update?\n");
    printf("1. Name\n");
    printf("2. Quantity\n");
    printf("3. Price\n");
    printf("4. All details\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter new name: ");
        getchar(); // consume newline
        fgets(item->name, sizeof(item->name), stdin);
        item->name[strcspn(item->name, "\n")] = 0; // remove newline
        break;
    case 2:
        printf("Enter new quantity: ");
        scanf("%d", &item->quantity);
        break;
    case 3:
        printf("Enter new price: ");
        scanf("%f", &item->price);
        break;
    case 4:
        printf("Enter new name: ");
        getchar();
        fgets(item->name, sizeof(item->name), stdin);
        item->name[strcspn(item->name, "\n")] = 0;
        printf("Enter new quantity: ");
        scanf("%d", &item->quantity);
        printf("Enter new price: ");
        scanf("%f", &item->price);
        break;
    default:
        printf("[ERROR] Invalid choice!\n");
        return;
    }
    printf("[SUCCESS] Item updated successfully!\n");
}

PNODE SearchByID(PNODE head, int id)
{
    while (head != NULL)
    {
        if (head->id == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

PNODE SearchByName(PNODE head, char name[])
{
    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void DisplayLowStock(PNODE head, int threshold)
{
    int found = 0;
    printf("\n[LOW STOCK ALERT] (Threshold: %d)\n", threshold);
    printf("==========================================\n");
    
    while (head != NULL)
    {
        if (head->quantity <= threshold)
        {
            printf("[WARNING] ID: %d | Name: %s | Quantity: %d\n", 
                   head->id, head->name, head->quantity);
            found = 1;
        }
        head = head->next;
    }
    
    if (!found)
    {
        printf("[SUCCESS] All items are adequately stocked!\n");
    }
}

float CalculateTotalValue(PNODE head)
{
    float total = 0.0;
    while (head != NULL)
    {
        total += (head->quantity * head->price);
        head = head->next;
    }
    return total;
}

void SortInventoryByPrice(PPNODE head)
{
    if (*head == NULL)
        return;

    int swapped;
    PNODE ptr1;
    PNODE lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr)
        {
            if (ptr1->price > ptr1->next->price)
            {
                // Swap data
                int tempId = ptr1->id;
                char tempName[30];
                int tempQty = ptr1->quantity;
                float tempPrice = ptr1->price;

                ptr1->id = ptr1->next->id;
                strcpy(tempName, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                ptr1->quantity = ptr1->next->quantity;
                ptr1->price = ptr1->next->price;

                ptr1->next->id = tempId;
                strcpy(ptr1->next->name, tempName);
                ptr1->next->quantity = tempQty;
                ptr1->next->price = tempPrice;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    
    printf("[SUCCESS] Inventory sorted by price (ascending)!\n");
}

void FreeInventory(PPNODE head)
{
    PNODE current = *head;
    PNODE next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
