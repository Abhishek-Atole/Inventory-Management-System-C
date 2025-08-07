#ifndef DATABASE_H
#define DATABASE_H

#include "inventory.h"

// Database Function Prototypes
int SaveInventoryToFile(PNODE head, char filename[]);
int LoadInventoryFromFile(PPNODE head, char filename[]);
void CreateBackup(PNODE head);
int ImportFromCSV(PPNODE head, char filename[]);
int ExportToCSV(PNODE head, char filename[]);

#endif