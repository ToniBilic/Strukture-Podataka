/*
2. Definirati strukturu osoba (ime, prezime, godina roðenja) i napisati program koji:
	A. dinamièki dodaje novi element na poèetak liste,
	B. ispisuje listu,
	C. dinamièki dodaje novi element na kraj liste,
	D. pronalazi element u listi (po prezimenu),
	E. briše odreðeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MEMORY_ALLOCATION_ERROR (-1)
#define	MAX_LINE (1024)
#define MAX_STRING (100)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person person;
typedef struct person* newPerson;

struct person{
	char name[MAX_STRING];
	char surname[MAX_STRING];
	int yearOfBirth;
	newPerson next;
};



int enterNewB(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, newPerson nP);

int enterNewE(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, newPerson nP);

int printList(newPerson nP);

int searchS(char surname[MAX_STRING], newPerson nP);

int delete(char name[MAX_STRING], char surname[MAX_STRING], newPerson nP);

int main() {
	newPerson head = (newPerson)malloc(sizeof(person));

	if (head == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	head->next = NULL;

	enterNewB("Jure", "Juric", 2000, head);
	enterNewB("Mate", "Matic", 2002, head);

	enterNewE("Stipe", "Stipic", 2004, head);

	printList(head->next);

	searchS("Stipic", head->next);

	delete("Stipe", "Stipic", head);

	printList(head->next);

	return 0;
}


int enterNewB(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, newPerson nP) {

	newPerson nB = NULL;

	nB = (newPerson)malloc(sizeof(person));

	if (nB == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	strcpy(nB->name, name);
	strcpy(nB->surname, surname);
	nB->yearOfBirth = yearOfBirth;

	nB->next = nP->next;
	nP->next = nB;

	return 0;
}

int enterNewE(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, newPerson nP) {

	newPerson nE = NULL;

	nE = (newPerson)malloc(sizeof(person));

	if (nE == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	while (nP->next != NULL) {
		nP = nP->next;
	}

	strcpy(nE->name, name);
	strcpy(nE->surname, surname);
	nE->yearOfBirth = yearOfBirth;

	nE->next = nP->next;
	nP->next = nE;

	return 0;
}

int printList(newPerson nP) {
	while (nP != NULL) {
		printf("%s %s %d \n", nP->name, nP->surname, nP->yearOfBirth);
		nP = nP->next;
	}
	return 0;
}

int searchS(char surname[MAX_STRING], newPerson nP) {
	while (nP != NULL) {
		if (!strcmp(nP->surname, surname)) {
			printf("%s %s %d \n", nP->name, nP->surname, nP->yearOfBirth);
		}
		nP = nP->next;
	}
	return 0;
}

int delete(char name[MAX_STRING], char surname[MAX_STRING], newPerson nP) {
	newPerson del = NULL;
	while (nP != NULL){
		del = nP;
		nP = nP->next;

		if (!strcmp(nP->name, name) && !strcmp(nP->surname, surname)) {
			del->next = nP->next;
			nP->next = NULL;
			return 0;
		}
	}
	return 0;

}
