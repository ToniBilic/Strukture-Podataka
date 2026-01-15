#include <stdlib.h>
#include <stdio.h>
#include "stuct.h"

int insertTree(tree* root, char* name, int pop) {
    if (!root) {
        tree* nE = (tree*)malloc(sizeof(tree));
        strcpy(nE->name, name);
        nE->population = pop;
        nE->left = nE->right = NULL;
        return nE;
    }

    if (pop > root->population || (pop == root->population && strcmp(name, root->name) < 0)) {
        root->left = insertTree(root->left, name, pop);
    }
    else {
        root->right = dodaj_grad(root->right, name, pop);
    }

    return root;
}

int insertList(list* hashTab[], char* name) {
    int i = hash(name);

    list* nE = (list*)malloc(sizeof(list));
    strcpy(nE->name, name);
    nE->root = NULL;
    nE->next = NULL;

    list* head = hashTab[i];

    if (!head || strcmp(name, head->name) < 0) {
        nE->next = head;
        hashTab[i] = nE;
        return EXIT_SUCCESS;
    }

    list* temp = head;
    while (temp->next && strcmp(temp->next->name, name) < 0)
        temp = temp->next;

    nE->next = temp->next;
    temp->next = nE;

    return EXIT_SUCCESS;
}