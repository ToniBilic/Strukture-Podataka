#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "errors.h"
#ifndef PRINT_H
#define PRINT_H

int inOrderPrint(tree* root);
int preOrderPrint(tree* root);
int postOrderPrint(tree* root);
int levelOrderPrint(tree* root);

#endif

