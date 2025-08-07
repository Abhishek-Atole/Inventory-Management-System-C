#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/database.h"

int SaveInventoryToFile(PNODE head, char filename[])
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("[ERROR] Could not open file '%s' for writing!\n", filename);
        return 0;
    }

    // Write header
    fprintf(fp, "ID,Name,Quantity,Price\n");
    
    // Write data
    while (head != NULL)
    {
        fprintf(fp, "%d,%s,%d,%.2f\n", head->id, head->name, head->quantity, head->price);
        head = head->next;
    }

    fclose(fp);
    printf("[SUCCESS] Inventory saved to '%s' successfully!\n", filename);
    return 1;
}

int LoadInventoryFromFile(PPNODE head, char filename[])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("[ERROR] Could not open file '%s' for reading!\n", filename);
        return 0;
    }

    char line[200];
    int id, quantity;
    char name[30];
    float price;
    int count = 0;
    int duplicates = 0;

    // Skip header line
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp))
    {
        // Remove newline character if present
        line[strcspn(line, "\r\n")] = 0;
        
        // Skip empty lines
        if (strlen(line) == 0) continue;
        
        // Parse CSV line
        char *token = strtok(line, ",");
        if (token == NULL) continue;
        id = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strcpy(name, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        quantity = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        price = atof(token);

        // Check if item already exists before adding
        if (SearchByID(*head, id) == NULL)
        {
            AddItemSilent(head, id, name, quantity, price);
            count++;
        }
        else
        {
            duplicates++;
        }
    }

    fclose(fp);
    printf("[SUCCESS] Loaded %d items from '%s' successfully!\n", count, filename);
    if (duplicates > 0)
    {
        printf("[INFO] Skipped %d duplicate items.\n", duplicates);
    }
    return 1;
}

void CreateBackup(PNODE head)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char filename[100];
    
    sprintf(filename, "backup_%04d%02d%02d_%02d%02d%02d.csv",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    SaveInventoryToFile(head, filename);
    printf("[INFO] Backup created: %s\n", filename);
}

int ImportFromCSV(PPNODE head, char filename[])
{
    return LoadInventoryFromFile(head, filename);
}

int ExportToCSV(PNODE head, char filename[])
{
    return SaveInventoryToFile(head, filename);
}