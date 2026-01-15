#include "tree.h"
#ifndef LIST_H
#define LIST_H
#define MAX_LINE 50

typedef struct list {
	char name[MAX_LINE];
	struct list* next;
	tree* treeEl;
}list;

int insert(list* next, char name[MAX_LINE]);
int clearList(list* head);

#endif
