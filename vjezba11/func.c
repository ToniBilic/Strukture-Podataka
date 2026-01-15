#include <stdlib.h>
#include <stdio.h>
#include "func.h"
#include "define.h"

int hash(char* name) {
	int sum = 0;
	for (int i = 0; i < 5 && name[i] != '\0'; i++) {
		sum += (int)name[i];
	}

	return sum % HASH_SIZE;
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

int printList(list* hashTab[]) {
    
    for (int i = 0; i < HASH_SIZE; i++) {
        
        list* tmp = hashTab[i];
        while (tmp) {
            printf("%s\n", tmp->name);
            ispisi_gradove(tmp->root);
            tmp = tmp->next;
        }
    }

    return EXIT_SUCCESS;
}

int searchList(list* hashTab[], char* name) {
    int i = hash(name);
    list* temp = hashTab[i];

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int searchTree(tree* root, int min) {
    if (root == NULL) {
        return TREE_EMPTY;
    }

    searchTree(root->left, min);
    searchTree(root->right, min);

    if (root->population > min) {
        printf("    %s (%d)\n", root->name, root->population);
    }

    return EXIT_SUCCESS;
}