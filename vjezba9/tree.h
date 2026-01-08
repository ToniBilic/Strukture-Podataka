#ifndef TREE_H
#define TREE_H

typedef struct tree {
	int value;
	struct tree* left;
	struct tree* right;

}tree;

int insert(tree* root, int value);
int insertR(tree* root, int valueR);
#endif
