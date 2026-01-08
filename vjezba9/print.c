#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "print.h"
#include "error.h"
#define _CRT_SECURE_NO_WARNINGS

int inOrderPrint(tree* root) {
	FILE* fp = NULL;
	fp = fopen("ispis.txt", "w");

	if (fp == NULL) {
		return FILE_NOT_OPENED;
	}

	if (root == NULL) {
		return TREE_EMPTY;
	}

	inOrderPrint(root->left);
	fprintf(fp, "%d ", root->value);
	inOrderPrint(root->right);

	return EXIT_SUCCESS;
}