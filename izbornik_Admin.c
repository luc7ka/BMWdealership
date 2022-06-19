#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"




void izbornik_Admin() {
	ADMIN admin = { "admin","admin",1 };
	int flag = 0;
	int odabir;
	int id;

	while (prijava_Admin(&admin) == false && flag < 4) {
		flag++;
		if (flag == 3) {
			printf("Neuspjesno logiranje iskoristeni svi pokusaji!");
			return;
		}
		system("cls");
		printf("Pogresno uneseno koristicko ime ili lozinka pokusaj ponovo: \n");
	}
	system("cls");
	printf("Uspjesa prijava.\n");

	do {
		system("cls");
		printf("Unesite koju radnju zelite da se izvrsi:\n");
		printf("1)dodavanje auta\n");
		printf("2)brisanje auta\n");
		printf("3)ispis svih auta\n");
		printf("0)izlaz iz programa\n");

		scanf("%d", &odabir);

		switch (odabir) {
		case 1:
			system("cls");
			unosNovogAuta();
			break;
		case 2:
			system("cls");
			printf("Unesite id automobila kojeg zelite obrisati: \n");
			scanf(" %d", &id);
			int stanje = brisanjeAuta(id);
			if (stanje == 1) {
				printf("Uspjesno izbrisan trazeni proizvid\n");
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
				
				void izbornik_Admin() {
	ADMIN admin = { "admin","admin",1 };
	ADMIN* admin_pok = &admin;
	int flag = 0;
	int odabir;
	int id;

	bool editSuccess;

	while (prijava_Admin(admin_pok) == false && flag < 4) {
		flag++;
		if (flag == 3) {
			printf("Neuspjesno logiranje iskoristeni svi pokusaji!");
			return;
		}
		system("cls");
		printf("Pogresno uneseno koristicko ime ili lozinka pokusaj ponovo: \n");
	}
	system("cls");
	printf("Uspjesa prijava.\n");

	do {
		system("cls");
		printf("Unesite koju radnju zelite da se izvrsi:\n");
		printf("1)dodavanje auta\n");
		printf("2)brisanje auta\n");
		printf("3)ispis svih auta\n");
		printf("4)edit postojeceg automobila\n");
		printf("0)izlaz iz programa\n"); 

		scanf("%d", &odabir);

		switch (odabir) {
		case 1:
			system("cls");
			unosNovogAuta();
			break;
		case 2:
			system("cls");
			printf("Unesite id automobila kojeg zelite obrisati: \n");
			scanf(" %d", &id);
			int stanje = brisanjeAuta(id);
			if (stanje == 1) {
				printf("Uspjesno izbrisan trazeni proizvid\n");
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
            printf("Unesite id automobila za edit: ");
            scanf(" %d", &idEdit);
          
            editSuccess = editAutomobila(idEdit);
            if(editSuccess == true){
                printf("Car (ID: %d) successfully edited", idEdit);
            }else{
                printf("No Car with given ID");
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

