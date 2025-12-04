#include "item.h"
#ifndef RECEIPT_H
#define RECEIPT_H

typedef struct receipt {
    char date[11];
    item* item;
    struct receipt* next;
} receipt;

int loadFile(receipt** head);
int loadReceipt(char* filename, receipt** head);
receipt* createReceipt();
int sortReceipt(receipt** head, receipt* new);
#endif 

