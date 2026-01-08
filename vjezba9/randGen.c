#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randGen() {
	srand(time(NULL));

	return rand() % 81 + 10;
}