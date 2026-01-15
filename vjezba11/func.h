#include "define.h"
#include "stuct.h"
#ifndef FUNC_H
#define FUNC_H

int hash(char* name);
int printTree(tree* root);
int printList(list* hashTab[]);
int searchList(list* hashTab[], char* name);
int searchTree(tree* root, int min);


#endif 