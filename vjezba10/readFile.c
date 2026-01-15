#include <stdlib.h>
#include <stdio.h>
#include "readFile.h"

int readFile(void* head, char filename[MAX_LINE]) {
	
	FILE* fp = NULL;
	char name[MAX_LINE], file[MAX_LINE];
	int population;

	if (filename == NULL) {
		return FILE_ERROR;
	}

	if (strcmp(filename, "drzave.txt") == 0) {
		fp = fopen(filename, "r");

		while (fscanf(fp, "%s %s", name, file)) {
			insert(head, name);
		}
	}
	else {
		fp = fopen(filename, "r");

		while (fscanf(fp, " %[^,],%d", name, population)) {
			insert(head, population, name);
		}
	}

	fclose(fp);

	return EXIT_SUCCESS;
}