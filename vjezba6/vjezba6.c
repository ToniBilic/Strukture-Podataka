#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "receipt.h"
#include "errors.h"

int main() {
	receipt* head = NULL;

	loadFile(&head);

	return 0;
}
