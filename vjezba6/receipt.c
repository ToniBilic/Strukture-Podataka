#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "receipt.h"
#include "item.h"
#include "errors.h"


int loadFile(receipt** head) {
	FILE* fp = fopen("receipt.txt", "r");

	if (fp == NULL) {
		return FILE_OPEN_ERROR;
	}

	char filename[100];

	while (fscanf(fp, "%s", filename) == 1) {
		loadReceipt(filename, head);
	}

	fclose(fp);
}

int loadReceipt(char* filename, receipt** head) {
	FILE* fp = fopen(filename, "r");
	
	if (fp == NULL) {
		return FILE_OPEN_ERROR;
	}

	receipt* r = createReceipt();

	char date[11];
	fscanf(fp, "%s\n", date);

	strcpy(r->date, date);

	char type[50];
	int q;
	float price;

	while (fscanf(fp, "%49[^,] %d %f", type, &q, &price) == 3) {
		item* i = createItem(type, q, price);
		sortItem(&r->item, i);
	}

	sortReceipt(head, r);
	fclose(fp);
}

receipt* createReceipt() {
	receipt* new = (receipt*)malloc(sizeof(receipt));
	new->item = NULL;
	new->next = NULL;
	return new;
}

int sortReceipt(receipt** head, receipt* new) {
	if (*head == NULL || strcmp(new->date, (*head)->date) < 0) {
		new->next = *head;
		*head = new;
		return EXIT_SUCCESS;
	}

	receipt* curr = *head;
	while (curr->next && strcmp(new->date, curr->next->date) > 0) {
		curr = curr->next;
	}
		
	new->next = curr->next;
	curr->next = new;

	return EXIT_SUCCESS;
}