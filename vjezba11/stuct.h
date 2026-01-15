#include "define.h"
#ifndef STRUCT_H
#define STRUCT_H

typedef struct tree{
    char name[MAX_LINE];
    int population;
    struct tree* left;
    struct tree* right;
} tree;

typedef struct list{
    char name[MAX_LINE];
    tree* root;
    struct list* next;
} list;


int insertTree(tree* root, char* name, int pop);
int insertList(list* hashTab[], char* name);
#endif 
