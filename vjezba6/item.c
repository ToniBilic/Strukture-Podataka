#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "errors.h"


item* createItem(char* type, int q, float price) {
	item* new = (item*)malloc(sizeof(item));
	strcpy(new->type, type);
	new->q = q;
	new->price = price;
	new->next = NULL;
}

int sortItem(item** head, item* new) {
    if (*head == NULL || strcmp(new->type, (*head)->type) < 0) {
        new->next = *head;
        *head = new;
        return EXIT_SUCCESS;
    }

    item* curr = *head;
    while (curr->next && strcmp(new->type, curr->next->type) > 0)
        curr = curr->next;

    new->next = curr->next;
    curr->next = new;

    return EXIT_SUCCESS;
}