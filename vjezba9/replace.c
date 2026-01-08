#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include "replace.h"

int replace(tree* root) {
	if (root == NULL) {
		return TREE_EMPTY;
	}

	int rightS = replace(root->right);
	int leftS = replace(root->left);
	int prevValue = root->value;

	root->value = rightS + leftS;

	return root->value + prevValue;
}