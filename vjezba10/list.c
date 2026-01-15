#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "errors.h"
#include "tree.h"

int insert(list* head, char name[MAX_LINE]) {

	list* nE = (list*)malloc(sizeof(list));

	if (nE == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	strcpy(nE->name, name);
	nE->next = NULL;


	if (head == NULL || strcmp(head->name, name) < 0) {
		nE->next = head;
		head = nE;
		return EXIT_SUCCESS;
	}

	list* tmp = head;

	while (tmp->next != NULL && strcmp(tmp->next->name, name) > 0) {
		tmp = tmp->next;
	}

	nE->next = tmp->next;
	tmp->next = nE;

	return EXIT_SUCCESS;
}

int clearList(list* head) {
	list* tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		clearTree(tmp->treeEl);

		tmp->next = NULL;
		free(tmp);
	}

	return EXIT_SUCCESS;
	
}