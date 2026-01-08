#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "error.h"
#include "randGen.h"

int insert(tree* root, int value) {
	if (root == NULL) {
		return TREE_EMPTY;
	}
	if (value >= root->value) {
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
		}
		else {
			return insert(root->left, value);
		}
	}
	else if (value < root->value) {
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
		}
		else {
			return insert(root->right, value);
		}
	}
	return EXIT_SUCCESS;
}

int insertR(tree* root, int valueR) {
	if (root == NULL) {
		return TREE_EMPTY;
	}
	if (valueR >= root->value) {
		if (root->left == NULL) {
			tree* nN = (tree*)malloc(sizeof(tree));
			if (nN == NULL) {
				return MEMORY_ALLOCATION_ERROR;
			}
			nN->value = valueR;
			nN->left = NULL;
			nN->right = NULL;
			root->left = nN;
			return EXIT_SUCCESS;
		}
		else {
			return insert(root->left, randGen());
		}
	}
	else if (valueR < root->value) {
		if (root->right == NULL) {
			tree* nN = (tree*)malloc(sizeof(tree));
			if (nN == NULL) {
				return MEMORY_ALLOCATION_ERROR;
			}
			nN->value = valueR;
			nN->left = NULL;
			nN->right = NULL;
			root->right = nN;
			return EXIT_SUCCESS;
		}
		else {
			return insert(root->right, randGen());
		}
	}
	return EXIT_SUCCESS;
}