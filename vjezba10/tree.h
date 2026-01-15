#ifndef TREE_H
#define TREE_H
#define MAX_LINE 50

typedef struct tree {
	int population;
	char name[MAX_LINE];
	struct tree* left;
	struct tree* right;

}tree;

int insert(tree* root, int population, char name[MAX_LINE]);
int clearTree(tree* root);
#endif