/*
10. 
Napisati program koji èita datoteku drzave.txt u kojoj su zapisani nazivi pojedinih država. Uz
ime države u datoteci se nalazi i ime dodatne datoteke u kojoj se nalaze gradovi pojedine
države. Svaka datoteka koja predstavlja državu sadrži popis gradova u formatu naziv_grada,
broj_stanovnika.

a) Potrebno je formirati sortiranu vezanu listu država po nazivu. Svaki èvor vezane liste
sadrži stablo gradova sortirano po broju stanovnika, zatim po nazivu grada.
b) Potrebno je formirati stablo država sortirano po nazivu. Svaki èvor stabla sadrži vezanu
listu gradova sortiranu po broju stanovnika, zatim po nazivu grada.

Nakon formiranja podataka potrebno je ispisati države i gradove te omoguæiti korisniku putem
tastature pretragu gradova odreðene države koji imaju broj stanovnika veæi od unosa na
tastaturi.
*/

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include "list.h"
#include "tree.h"
#include "readFile.h"
#include "func.h"

int main() {
	list* head = NULL;
	head->next = NULL;
	head->treeEl = NULL;

	readFile(head, "drzave.txt");

	char name[MAX_LINE];
	int min;

	scanf("%s", name);
	scanf("%d", min);

	searchList(head, name, min);

	clearList(head);

	return 0;
}