#include <stdlib.h>
#include <stdio.h>
#include "func.h"
#include "errors.h"

int printList(list* head) {
    while (head != NULL) {
        printf("Drzava: %s\n", head->name);
        printTree(head->treeEl);
        head = head->next;
    }

    return EXIT_SUCCESS;
}

int printTree(tree* root) {
    if (root == NULL) {
        return TREE_EMPTY;
    }

    printTree(root->left);
    printf("    %s (%d)\n", root->name, root->population);
    printTree(root->right);

    return EXIT_SUCCESS;
}

int searchList(list* head, char name[MAX_LINE], int min) {
    while (head != NULL && strcmp(head->name, name) != 0)
        head = head->next;

    searchTree(head->treeEl, min);

    return EXIT_SUCCESS;
}


int searchTree(tree* root, int min) {
    if (root == NULL) {
        return TREE_EMPTY;
    }

    searchTree(root->left, min);

    if (root->population > min) {
        printf("    %s (%d)\n", root->name, root->population);
    }

    searchTree(root->right, min);

    return EXIT_SUCCESS;
}