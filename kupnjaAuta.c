#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


void kupnjaAuta() {
	AUTO* auti = NULL;
	AUTO temp;
	auti = ucitavanjeAuta(auti);
	int brAuta = ucitavanjeBrojaAuta();

	int i;
	int flag = 0;

	char* ne = "ne";
	char* da = "da";
	char unos[3];
	int stanje = 0;

	FILE* datoteka;
	char* ime_dat = "prodaniAuti.txt";

	printf("Unesite ID auta koji zelite kupiti: ");
	scanf("%d", &temp.id);
	system("cls");

	for (i = 0; i < brAuta; i++) {
		if ((auti + i)->id == temp.id) {
			printf("Jeste li mislili na ovaj automobil?:\n\n");
			printf("Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
			printf("\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
			printf("\n\n");
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("Nema auta s tim ID-om");
		printf("\n\nPritisnite bilo koju tipku za povratak u izbornik\n");
		_getch();
		return;
	}

	printf("Unesite 'da' ili 'ne':  ");

	do {
		scanf(" %2s", &unos);
		if (strcmp(ne, unos) == 0) {
			printf("\n\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			return;
		}
		if (strcmp(da, unos) == 0) {
			break;
		}
		if (strcmp(da, unos) != 0 || strcmp(ne, unos) != 0) {
			printf("\nKrivi unos, unesite 'da' ili 'ne':  ");
		}
	} while (1);

	system("cls");

	datoteka = fopen(ime_dat, "a");
	if (datoteka == NULL) {
		printf("Nije moguce otvoriti datoteku\n ");
		exit(EXIT_FAILURE);
	}
	else {
		for (i = 0; i < brAuta; i++) {
			if ((auti + i)->id == temp.id) {
				fprintf(datoteka, "Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
				fprintf(datoteka, "\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
				fprintf(datoteka, "\n\n");
				flag = 1;
			}
		}
		fclose(datoteka);
	}
	stanje = brisanjeAuta(temp.id);
	if (stanje == 1) {
		printf("Uspjesno kupljen auto\n");
	}
	if (stanje == 0) {
		printf("Neuspjesna kupovina, molimo pokusajte ponovo");
	}
	printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
	_getch();

}
