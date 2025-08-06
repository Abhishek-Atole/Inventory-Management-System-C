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
void DisplayInventory(PNODE head);
int CountItems(PNODE head);

#endif
