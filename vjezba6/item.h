
#ifndef ITEM_H
#define ITEM_H

typedef struct item {
    char type[50];
    int q;
    float price;
    struct item* next;
} item;

item* createItem(char* type, int q, float price);
int sortItem(item** head, item* new);
#endif

