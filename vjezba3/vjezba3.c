/*
3. Prethodnom zadatku dodati funkcije:
	A. dinamièki dodaje novi element iza odreðenog elementa,
	B. dinamièki dodaje novi element ispred odreðenog elementa,
	C. sortira listu po prezimenima osoba,
	D. upisuje listu u datoteku,
	E. èita listu iz datoteke.
*/


#define _CRT_SECURE_NO_WARNINGS
#define MEMORY_ALLOCATION_ERROR (-1)
#define FILE_NOT_OPEN (-2)
#define	MAX_LINE (1024)
#define MAX_STRING (100)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person person;
typedef struct person* newPerson;

struct person {
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

//funkcije 3. zadatka
int enterNewAfter(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, int after, newPerson nP);

int enterNewBefore(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, int before, newPerson nP);

int sortList(newPerson head);

int printListF(newPerson nP);

int readListF(newPerson nP);


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

	printListF(head->next);

	readListF(head->next);

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
	while (nP != NULL) {
		del = nP;
		nP = nP->next;

		if (!strcmp(nP->name, name) && !strcmp(nP->surname, surname)) {
			del->next = nP->next;
			nP->next = NULL;
			free(nP);
			return 0;
		}
	}
	return 0;

}

int enterNewAfter(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, int after, newPerson nP) {

	newPerson nA = NULL;
	int i = 0;

	nA = (newPerson)malloc(sizeof(person));

	if (nA == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	strcpy(nA->name, name);
	strcpy(nA->surname, surname);
	nA->yearOfBirth = yearOfBirth;

	while (i < after && nP->next != NULL) {
		nP = nP->next;
		i++;
	}

	nA->next = nP->next;
	nP->next = nA;

	return 0;
}

int enterNewBefore(char name[MAX_STRING], char surname[MAX_STRING], int yearOfBirth, int before, newPerson nP) {

	newPerson nB = NULL;
	int i = 0;

	nB = (newPerson)malloc(sizeof(person));

	if (nB == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	strcpy(nB->name, name);
	strcpy(nB->surname, surname);
	nB->yearOfBirth = yearOfBirth;

	while (i < (before-1) && nP->next != NULL) {
		nP = nP->next;
		i++;
	}

	nB->next = nP->next;
	nP->next = nB;

	return 0;
}

int printListF(newPerson nP) {
	FILE* fp = NULL;

	fp = fopen("people.txt", "w");

	if (fp == NULL) {
		return FILE_NOT_OPEN;
	}

	while (nP != NULL) {
		fprintf(fp, "%s %s %d \n", nP->name, nP->surname, nP->yearOfBirth);
		nP = nP->next;
	}

	fclose(fp);

	return 0;
}

int readListF(newPerson nP) {
	FILE* fp = NULL;

	fp = fopen("people.txt", "r");

	if (fp == NULL) {
		return FILE_NOT_OPEN;
	}

	while (!feof(fp)) {
		fscanf(fp, "%s %s %d", nP->name, nP->surname, nP->yearOfBirth);
		nP = nP->next;
	}

	fclose(fp);

	return 0;
}