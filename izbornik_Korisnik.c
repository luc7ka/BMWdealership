#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

void izbornik_Korisnik() {
	int odabir;
	int i, j;
	int flag = 0;
	int brAuta = ucitavanjeBrojaAuta();
	AUTO* auti = NULL;
	AUTO temp;
	auti = ucitavanjeAuta(auti);
	FILE* datoteka;
	char* ime_dat = "auti.txt";


	do {
		system("cls");
		printf("Unesite koju radnju zelite da se izvrsi:\n");
		printf("1)ispis svih auta\n");
		printf("2)Ispis svih auta sortiranih po cijeni uzlazno\n");
		printf("3)Ispis svih auta sortiranih po cijeni silazno\n");
		printf("4)Ispis auta vece snage motora od navedenog\n");
		printf("5)Pretraga auta po modelu\n");
		printf("6)Pretraga auta po boji\n");
		printf("7)Ispis auta u tekstualnoj datoteci (auti.txt)\n");
		printf("8)Kupnja auta\n");
		printf("0)izlaz iz programa\n");

		scanf("%d", &odabir);

		system("cls");

		switch (odabir) {
		case 1:
			ispisAuta();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
		case 2:
			for (i = 0; i < brAuta - 1; i++) {
				for (j = 0; j < brAuta - 1 - i; j++) {
					if ((auti + j + 1)->cijena < (auti + j)->cijena) {
						strcpy(temp.model, (auti + j)->model);
						strcpy(temp.boja, (auti + j)->boja);
						temp.godina_proizvodnje = (auti + j)->godina_proizvodnje;
						temp.snaga_motora = (auti + j)->snaga_motora;
						temp.cijena = (auti + j)->cijena;
						temp.id = (auti + j)->id;

						strcpy((auti + j)->model, (auti + j + 1)->model);
						strcpy((auti + j)->boja, (auti + j + 1)->boja);
						(auti + j)->godina_proizvodnje = (auti + j + 1)->godina_proizvodnje;
						(auti + j)->snaga_motora = (auti + j + 1)->snaga_motora;
						(auti + j)->cijena = (auti + j + 1)->cijena;
						(auti + j)->id = (auti + j + 1)->id;

						strcpy((auti + j + 1)->model, temp.model);
						strcpy((auti + j + 1)->boja, temp.boja);
						(auti + j + 1)->godina_proizvodnje = temp.godina_proizvodnje;
						(auti + j + 1)->snaga_motora = temp.snaga_motora;
						(auti + j + 1)->cijena = temp.cijena;
						(auti + j + 1)->id = temp.id;
					}
				}
			}
			printf("Popis je sortiran od manje cijene prema vecoj\n\n");
			for (i = 0; i < brAuta; i++) {
				printf("Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
				printf("\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
				printf("\n\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
		case 3:
			for (i = 0; i < brAuta - 1; i++) {
				for (j = 0; j < brAuta - 1 - i; j++) {
					if ((auti + j + 1)->cijena > (auti + j)->cijena) {
						strcpy(temp.model, (auti + j)->model);
						strcpy(temp.boja, (auti + j)->boja);
						temp.godina_proizvodnje = (auti + j)->godina_proizvodnje;
						temp.snaga_motora = (auti + j)->snaga_motora;
						temp.cijena = (auti + j)->cijena;
						temp.id = (auti + j)->id;

						strcpy((auti + j)->model, (auti + j + 1)->model);
						strcpy((auti + j)->boja, (auti + j + 1)->boja);
						(auti + j)->godina_proizvodnje = (auti + j + 1)->godina_proizvodnje;
						(auti + j)->snaga_motora = (auti + j + 1)->snaga_motora;
						(auti + j)->cijena = (auti + j + 1)->cijena;
						(auti + j)->id = (auti + j + 1)->id;

						strcpy((auti + j + 1)->model, temp.model);
						strcpy((auti + j + 1)->boja, temp.boja);
						(auti + j + 1)->godina_proizvodnje = temp.godina_proizvodnje;
						(auti + j + 1)->snaga_motora = temp.snaga_motora;
						(auti + j + 1)->cijena = temp.cijena;
						(auti + j + 1)->id = temp.id;
					}
				}
			}
			printf("Popis je sortiran od vece cijene prema manjoj\n\n");
			for (i = 0; i < brAuta; i++) {
				printf("Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
				printf("\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
				printf("\n\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
		case 4:
			printf("Unesite snagu motora:\n");
			scanf("%d", &temp.snaga_motora);
			printf("\n");
			for (i = 0; i < brAuta; i++) {
				if ((auti + i)->snaga_motora > temp.snaga_motora) {
					printf("Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
					printf("\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0 && i == brAuta - 1) {
				printf("Trenutacno nema auta te ili vece snage motora\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;

		case 5:
			printf("Unesite model trazenog auta:\n");
			scanf(" %29s", &temp.model);
			for (i = 0; i < brAuta; i++) {
				if (strcmp((temp.model), (auti + i)->model) == 0) {
					printf("Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
					printf("\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0) {
				printf("Trenutacno nema auta tog modela\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
		case 6:
			printf("Unesite boju trazenog auta:\n");
			scanf(" %29s", &temp.boja);
			for (i = 0; i < brAuta; i++) {
				if (strcmp((temp.boja), (auti + i)->boja) == 0) {
					printf("Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
					printf("\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0) {
				printf("Trenutacno nema auta zeljene boje\n");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
		case 7:
			datoteka = fopen(ime_dat, "w");
			if (datoteka == NULL) {
				printf("Ne mogucnost otvaranja datoteke\n ");
				exit(EXIT_FAILURE);
			}
			else {
				for (i = 0; i < brAuta; i++) {
					fprintf(datoteka, "Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
					fprintf(datoteka, "\nSnaga motora: %d \nCijena: %d \nID: %d\n\n", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
				}
				printf("Preuzmite datoeku s zeljenim podatcima(proizvodi.txt).\n");
				fclose(datoteka);
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
		case 8:
			kupnjaAuta();
			auti = ucitavanjeAuta(auti);
			brAuta = ucitavanjeBrojaAuta();
			break;

		case 0:
			odabir = krajPrograma();
			if (odabir == 0) {
				system("cls");
				printf("Kraj programa, stisnite bilo koju tipku za zavrsetak\n");
				_getch();
				system("cls");
				exit(EXIT_SUCCESS);
			}
			else {
				printf("Pritisnite bilo koju tipku za nastavak programa\n");
			}
			break;
		}

	} while (odabir != 0);
}


