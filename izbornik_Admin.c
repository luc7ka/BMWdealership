#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"




void izbornik_Admin() {
	ADMIN admin = { "admin","admin",1 };

	int flag = 0;
	int odabir;
	int id;

	int idEdit;
	bool editSuccess;

	while (prijava_Admin(&admin) == false && flag < 4) {
		flag++;
		if (flag == 3) {
			printf("Neuspjesno logiranje, iskoristili ste sve pokusaje!");
			return;
		}
		system("cls");
		printf("Pogresno uneseno korisnicko ime ili lozinka. \n");
		printf("Pokusaj ponovno: \n");
	}
	system("cls");
	printf("Uspjesna prijava.\n");

	do {
		system("cls");
		printf("Unesite koju radnju zelite izvrsiti:\n");
		printf("1)dodavanje auta\n");
		printf("2)brisanje auta\n");
		printf("3)ispis svih auta\n");
		printf("4)uredjivanje postojeceg automobila\n");
		printf("0)izlaz iz programa\n");

		scanf("%d", &odabir);

		switch (odabir) {
		case 1:
			system("cls");
			unosNovogAuta();
			break;
		case 2:
			system("cls");
			printf("Unesite ID automobila kojeg zelite obrisati: \n");
			scanf(" %d", &id);
			int stanje = brisanjeAuta(id);
			if (stanje == 1) {
				printf("Uspjesno izbrisan trazeni proizvod\n");
			}
			if (stanje == 0) {
				printf("Neuspjesno obrisan proizvod");
			}
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
		case 3:
			system("cls");
			ispisAuta();
			printf("\nPritisnite bilo koju tipku za povratak u izbornik\n");
			_getch();
			break;
			
		case 4:
			system("cls");
			printf("Unesite ID automobila za uredjivanje: ");
			scanf(" %d", &idEdit);
			
			editSuccess = editAutomobila(idEdit);
			if (editSuccess == true) {
				printf("Automobil (ID: %d) uspjesno uredjen", idEdit);
			}
			else {
				printf("Ne postoji automobil sa trazenim ID-om");
			}
			
			_getch();
			break;
		case 0:
			odabir = krajPrograma();
			if (odabir == 0) {
				system("cls");
				printf("Kraj programa, stisnite bilo koju tipku za zavrsetak\n");
				_getch();
				exit(EXIT_SUCCESS);
			}
			else {
				printf("Pritisnite bilo koju tipku za nastavak programa\n");
			}
			break;
		}

	} while (odabir != 0);
}
