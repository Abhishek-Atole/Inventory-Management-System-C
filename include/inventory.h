#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct node
{
    int id;
    char name[30];
    int quantity;
    float price;
    struct node *next;
} NODE, *PNODE, **PPNODE;

// Function Prototypes
void AddItem(PPNODE head, int id, char name[], int qty, float price);
void AddItemSilent(PPNODE head, int id, char name[], int qty, float price);
void DisplayInventory(PNODE head);
int CountItems(PNODE head);
void DeleteItem(PPNODE head, int id);
void UpdateItem(PNODE head, int id);
PNODE SearchByID(PNODE head, int id);
PNODE SearchByName(PNODE head, char name[]);
void DisplayLowStock(PNODE head, int threshold);
float CalculateTotalValue(PNODE head);
void SortInventoryByPrice(PPNODE head);
void FreeInventory(PPNODE head);

#endif
