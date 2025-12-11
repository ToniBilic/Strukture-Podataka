#include "element.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int addChild(element* head, char name[50]) {
	element* nE = NULL;

	nE = (element*)malloc(sizeof(element));

	if (nE == NULL) {
		return EXIT_FAILURE;
	}

	strcpy(nE->name, name);

	nE->next = head->next;
	head->next = nE;
	nE->prev = head;

	return nE;
}

int cd(element* head, element* child) {
	head = child;
	return head;
}

int cdPrev(element* head) {
	head = head->prev;
	return head;
}