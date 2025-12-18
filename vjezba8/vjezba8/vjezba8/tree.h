#ifndef TREE_H
#define TREE_H

typedef struct tree {
	int value;
	struct tree* left;
	struct tree* right;
}tree;

int addTree(tree* root, int value);

#endif 
