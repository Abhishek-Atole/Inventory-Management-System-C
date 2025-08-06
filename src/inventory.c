#include <stdio.h>
#include <stdlib.h>
#include "../include/inventory.h"

void AddItem(PPNODE head, int id, char name[], int qty, float price)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
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
    printf("\n---- Current Inventory ----\n");
    while (head != NULL)
    {
        printf("ID: %d | Name: %s | Quantity: %d | Price: ₹%.2f\n",
               head->id, head->name, head->quantity, head->price);
        head = head->next;
    }
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
