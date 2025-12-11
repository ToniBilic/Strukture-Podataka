#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct element {
	char name[50];
	struct element* next;
	struct element* prev;
}element;

element* addChild(element* head, char name[50]);
element* cd(element* curr, element* child);
element* cdPrev(element* curr);
#endif

