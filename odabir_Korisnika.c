#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int odabir_Korisnika() {

	int odabir;

	printf("Dobrodosli u trgovinu.\n");
	printf("	1)Korisnicki pristup\n");
	printf("	2)Administratorski pristup\n");
	printf("	0)Izlazak iz programa;\n");
	printf("Odaberite broj ispred radnje koju zelite:  ");



	scanf(" %d", &odabir);
	if (odabir < 0 || odabir>2) {
		system("cls");
		printf("\nNeispravan unos, pokusajte ponovo.\n");
		odabir_Korisnika();
	}
	system("cls");
	return odabir;

}

int krajPrograma(void) {
	int kraj;
	char* nastavak = "ne";
	char* zavrsetak = "da";
	char unos[3];
	printf("\nJeste li sigurni da zelite izaci iz programa?\n");
	printf("Ako ste sigurni onda unesite 'da' \nAko zelite i dalje nastaviti koristiti program unesite 'ne' i biti cete vraceni u izbornik\n");
	do {
		scanf(" %2s", &unos);
		if (strcmp(zavrsetak, unos) == 0) {
			kraj = 0;
			break;
		}
		if (strcmp(nastavak, unos) == 0) {
			kraj = 1;
			break;
		}
		if (strcmp(nastavak, unos) != 0 || strcmp(zavrsetak, unos) != 0) {
			printf("Krivi unos, trebate unesti 'da' ili 'ne'\n");
		}
	} while (1);
	return kraj;
} 
