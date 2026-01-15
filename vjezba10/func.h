#include "tree.h"
#include "list.h"

#ifndef FUNC_H
#define FUNC_H

int printList(list* head);

int printTree(tree* root);

int searchTree(tree* root, int min);

int searchList(list* head, char name[MAX_LINE], int min);
#endif 
