#include <stdlib.h>
#include <stdio.h>
#include "element.h"

int main() {
	element* head;

	addChild(head, "mainFile");
	cd(head, "mainFile");
	addChild(mainFile, "firstChild");
	cd(mainFile, firstChild);
	cdPrev(firstChild);

	return 0;
}