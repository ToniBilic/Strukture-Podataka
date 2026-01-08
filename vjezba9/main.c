#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include "randGen.h"
#include "replace.h"
#include "tree.h"
#include "print.h"

int main() {
	tree* root = (tree*)malloc(sizeof(tree));
	tree* rootR = (tree*)malloc(sizeof(tree));
	
	if (root == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	if (rootR == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	root->value = 2;
	root->left = NULL;
	root->right = NULL;

	insert(root, 5);
	insert(root, 7);
	insert(root, 8);
	insert(root, 11);
	insert(root, 1);
	insert(root, 4);
	insert(root, 2); 
	insert(root, 3); 
	insert(root, 7);
	replace(root);


	rootR->value = randGen();
	rootR->left = NULL;
	rootR->right = NULL;

	insert(rootR, randGen());
	insert(rootR, randGen());
	insert(rootR, randGen());
	insert(rootR, randGen());
	insert(rootR, randGen());
	replace(rootR);

	inOrder(rootR);

	return 0;
}