#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "print.h"
#include "errors.h"

int main() {

	tree* root = (tree*)malloc(sizeof(tree));
	
	if (root == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	root->value = 5;
	root->left = NULL;
	root->right = NULL;

	addTree(root, 3);
	addTree(root, 7);
	addTree(root, 2);
	addTree(root, 4);
	addTree(root, 6);
	addTree(root, 8);
	inOrderPrint(root);
	preOrderPrint(root);
	postOrderPrint(root);
	
	return 0;
}