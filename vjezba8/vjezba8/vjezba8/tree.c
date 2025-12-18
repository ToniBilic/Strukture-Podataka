#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 
#include "errors.h"

int addTree(tree* root, int value) {
	if (root == NULL) {
		return MEMORY_ALLOCATION_ERROR; 
	}
	if (value < root->value) {
		if (root->left == NULL) {
			tree* nN = (tree*)malloc(sizeof(tree));
			if (nN == NULL) {
				return MEMORY_ALLOCATION_ERROR; 
			}
			nN->value = value;
			nN->left = NULL;
			nN->right = NULL;
			root->left = nN;
			return EXIT_SUCCESS;
		} else {
			return addTree(root->left, value);
		}
	} else if (value >= root->value) {
		if (root->right == NULL) {
			tree* nN = (tree*)malloc(sizeof(tree));
			if (nN == NULL) {
				return MEMORY_ALLOCATION_ERROR;
			}
			nN->value = value;
			nN->left = NULL;
			nN->right = NULL;
			root->right = nN;
			return EXIT_SUCCESS;
		} else {
			return addTree(root->right, value);
		}
	} 
	return 0;
}