#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "errors.h"


int insert(tree* root, int population, char name[MAX_LINE]) {
	if (root == NULL) {
		return TREE_EMPTY;
	}
	if (population <= root->population) {
		if (root->left == NULL) {
			tree* nN = (tree*)malloc(sizeof(tree));
			if (nN == NULL) {
				return MEMORY_ALLOCATION_ERROR;
			}
			nN->population = population;
			strcpy(nN->name, name);
			nN->left = NULL;
			nN->right = NULL;
			root->left = nN;
			return EXIT_SUCCESS;
		}
		else {
			return insert(root->left, population, name);
		}
	}
	else if (population > root->population) {
		if (root->right == NULL) {
			tree* nN = (tree*)malloc(sizeof(tree));
			if (nN == NULL) {
				return MEMORY_ALLOCATION_ERROR;
			}
			nN->population = population;
			nN->left = NULL;
			nN->right = NULL;
			root->right = nN;
			return EXIT_SUCCESS;
		}
		else {
			return insert(root->right, population, name);
		}
	}
	return EXIT_SUCCESS;
}

int clearTree(tree* root) {
	if (root == NULL) {
		return TREE_EMPTY;
	}

	clearTree(root->left);
	clearTree(root->right);

	root->left = NULL;
	root->right = NULL;
	free(root);
}