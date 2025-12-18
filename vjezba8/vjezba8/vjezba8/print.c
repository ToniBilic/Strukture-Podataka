#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "print.h"
#include "errors.h"

int inOrderPrint(tree* root) {
	if (root == NULL) {
		return TREE_EMPTY_ERROR;
	}
	inOrderPrint(root->left);
	printf("%d ", root->value);
	inOrderPrint(root->right);
	return EXIT_SUCCESS;
}

int preOrderPrint(tree* root) {
	if (root == NULL) {
		return TREE_EMPTY_ERROR;
	}
	printf("%d ", root->value);
	preOrderPrint(root->left);
	preOrderPrint(root->right);
	return EXIT_SUCCESS;
}

int postOrderPrint(tree* root) {
	if (root == NULL) {
		return TREE_EMPTY_ERROR;
	}
	postOrderPrint(root->left);
	postOrderPrint(root->right);
	printf("%d ", root->value);
	return EXIT_SUCCESS;
}
