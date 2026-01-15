#include <stdlib.h>
#include <stdio.h>
#include "define.h"
#include "func.h"
#include "stuct.h"

int main() {
    list* hashTab[HASH_SIZE] = NULL;

    FILE* fp = fopen("drzave.txt", "r");
    if (fp == NULL) {
         return FILE_ERROR;
    }

    char name[MAX_LINE], filename[MAX_LINE];

    while (fscanf(fp, "%s %s", name, filename)) {
        insertList(hashTab, name);
        list* tmp = searchList(hashTab, name);
        insertTree(tmp, filename);
    }
    fclose(fp);

    printTree(hashTab);

    int min;

    scanf("%s", name);
    scanf("%d", &min);

    list* tmp = searchList(hashTab, name);
    if (tmp) {
        searchTree(tmp->root, min);
    }

    return 0;
}