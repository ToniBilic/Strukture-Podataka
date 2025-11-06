/*
5. Napisati program koji iz datoteke èita postfiks izraz i zatim korištenjem stoga raèuna
rezultat. Stog je potrebno realizirati preko vezane liste.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MEMORY_ALLOCATION_ERROR (-1)
#define FILE_NOT_OPENED (-2)
#define SUCCESS (0)
#define FAILIURE (1)
#define	MAX_LINE (1024)
#define MAX_STRING (100)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack stack;
typedef struct stack* newStack;

struct stack {
	int value;
	newStack next;
};

int addToStack(int value, newStack nS); //funkcija za dodavanje elemenata na stack
int readFile(newStack head);
int sum(newStack head);
int printSum(newStack nS);

int main() {

	newStack head = (newStack)malloc(sizeof(stack));
	head->value = NULL;
	head->next = NULL;

	readFile(head);

	printSum(head->next);

	return SUCCESS;
}


int readFile(newStack head) {

	FILE* fp = NULL;
	char buffer[MAX_LINE];
	int i = 0;

	fp = fopen("postfix.txt", "r");

	if (fp == NULL) {
		return FILE_NOT_OPENED;
	}

	fgets(buffer, MAX_LINE, fp);

	while (buffer[i] != " ") {
		if (buffer[i] >= 0 && buffer[i] < 10) {

			addToStack(buffer[i], head);
			
		}
		else if (buffer[i] = "+") {

			sum(head);
			
		}

		i++;
	}

	return SUCCESS;
}

int addToStack(int value, newStack nS) {

	newStack nE = NULL;

	nE = (newStack)malloc(sizeof(stack));

	if (nE == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}

	nE->value = value;

	nE->next = nS->next;
	nS->next = nE;

	return SUCCESS;
}


int sum(newStack head) {
	
	int f = 0, s = 0;
	newStack sum = NULL;

	sum = (newStack)malloc(sizeof(stack));

	if (sum == NULL) {
		return MEMORY_ALLOCATION_ERROR;
	}
	
	f = head->next->value;
	s = head->next->next->value;

	head->next->value = NULL;
	head->next->next->value = NULL;

	sum->next = head->next->next->next;

	head->next->next->next = NULL;
	free(head->next->next);
	head->next->next = NULL;
	free(head->next);

	head->next = sum;

	sum->value = f + s;

	return SUCCESS;
}

int printSum(newStack nS) {
	
	FILE* fp = NULL;

	fp = fopen("postfix.txt", "w");

	if (fp = NULL) {
		return FILE_NOT_OPENED;
	}

	fprintf(fp, "%d", nS->value);

	return SUCCESS;
}
