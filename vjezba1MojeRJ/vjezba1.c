/*
1. Napisati program koji prvo proèita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamièki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i uèitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100
*/

#define _CRT_SECURE_NO_WARNINGS
#define FILE_NOT_OPENED (-1)
#define MEMORY_ALLOCATION_ERROR (-2)
#define MAX_LINE (1024)
#define MAX_POINTS (120)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[MAX_LINE];
	char surname[MAX_LINE];
	int points;
}student;

int countStud();	// funk. za prebrojavanja studenata
int loadStud(student* s, int studCount);	// funk. za uèitavanje studenata iz datoteke
double percentage(int p);	// funk. za raèunanje postotka
int printStud(student* s, int studCount);	// funk. za ispis studenata 


int main() {
	student* s = NULL;
	int i = 0, studCount = 0;

	studCount = countStud();
	
	
	s = (student*)malloc(studCount * sizeof(student));

	if (s == NULL) {	// provjera alokacije memorije
		return MEMORY_ALLOCATION_ERROR;
	}

	// pozivi funkcija za uèitavanje i ispis studenata
	loadStud(s, studCount); 

	printStud(s, studCount);
	
	return 0;
}

int countStud() {	// funkcija za prebrojavanja studenata 
	FILE* fp = NULL;
	int cS = 0;
	char buff[MAX_LINE];

	fp = fopen("studenti.txt", "r");	// otvaranje datoteke

	if (fp == NULL){	// provjera je li se datoteka ispravno otvorila 
		return FILE_NOT_OPENED;
	}

	while (!feof(fp)) {		// prebrojavanje linija datoteke (1 student = 1 linija)
		fgets(buff, MAX_LINE, fp);
		cS++;
	}

	fclose(fp);		// zatvaranje datoteke
	return cS;		// slanje povratne vrijednosti (broj prebrojanih studenata)
}

int loadStud(student* s, int studCount) {	// funkcija za uèitavanja studenata
	FILE* fp = NULL;
	int i = 0;

	fp = fopen("studenti.txt", "r");	// otvaranje datoteke

	if (fp == NULL) {	// provjera je li se datoteka ispravno otvorila
		return FILE_NOT_OPENED;
	}

	while (i < studCount) {		// uèitavanje iz datoteke u odgovarajuæe varijable za svakog studenta 
		fscanf(fp, "%s %s %d", s[i].name, s[i].surname, &s[i].points);
		i++;
	}

	fclose(fp);		// zatvaranje datoteke

	return 0;
}

int printStud(student* s, int studCount) {		// funkcija za ispis studenata 
	int i = 0;
	
	while (i < studCount) {		// ispis studenata i njihovih bodova i postotaka
		printf("Student: %s %s absP: %d relP: %.2f \n", s[i].name, s[i].surname, s[i].points, percentage(s[i].points));
		i++;
	}
	
	return 0;
}

double percentage(int p) {		//funkcija za raèunanje postotka 
	return (double)p / MAX_POINTS * 100;
}
