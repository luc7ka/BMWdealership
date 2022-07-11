#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void kreiranjeDatotekeAuti() {
	FILE* datAuti = NULL;
	char* ime_dat = "auti.bin";
	datAuti = fopen(ime_dat, "rb");
	if (datAuti == NULL) {
		datAuti = fopen(ime_dat, "wb");
		if (datAuti == NULL) {
			printf("Nije moguce kreirati datoteku auti.bin\n ");
			printf("\nKraj programa\n");
			exit(EXIT_FAILURE);
		}
		else {
			printf("Uspjesno ste kreirali datoteku auti.bin\n");
			fclose(datAuti);
		}
	}
	else {
		fclose(datAuti);
	}
}

AUTO* ucitavanjeAuta(AUTO* automobil) {
	FILE* datoteka = NULL;
	char* ime_dat = "auti.bin";
	int broj_proizvoda = ucitavanjeBrojaAuta();
	automobil = (AUTO*)calloc(broj_proizvoda, sizeof(AUTO));
	if (automobil != NULL) {
		datoteka = fopen(ime_dat, "rb");
		if (datoteka == NULL) {
			printf("Neuspjesno otvaranje datoteke za citanje\n");
		}
		else {
			rewind(datoteka);
			fseek(datoteka, 4, SEEK_SET);
			fread(automobil, sizeof(AUTO), broj_proizvoda, datoteka);
			fclose(datoteka);
		}
	}
	return automobil;
}

int ucitavanjeBrojaAuta() {
	int brAuta = 0;
	FILE* datoteka = NULL;
	char* ime_dat = "auti.bin";
	datoteka = fopen(ime_dat, "rb");
	if (datoteka != NULL) {
		rewind(datoteka);
		fread(&brAuta, sizeof(int), 1, datoteka);
		fclose(datoteka);
	}
	else {
		printf("Nije moguce saznati koliki je broj auta u datoteci\n");
		printf("\nKraj programa\n");
		exit(EXIT_FAILURE);
	}
	return brAuta;
}

void unosNovogAuta() {
	AUTO noviAuto = { 0 };
	AUTO* sviAuti = NULL;
	FILE* datoteka = NULL;
	int flag = 1;
	int i = 0;
	char* ime_dat = "auti.bin";
	int brojAuta = ucitavanjeBrojaAuta();
	if (brojAuta == 0) {
		datoteka = fopen(ime_dat, "rb+");
		if (datoteka != NULL) {
			if (datoteka == NULL) {
				printf("Nije moguce kreirati datoteku auti.bin\n ");
				printf("\nKraj programa\n");
				exit(EXIT_FAILURE);
			}
			else {
				printf("Unesite ime modela\n");
				getchar();
				scanf("%29[^\n]", &noviAuto.model);
				printf("Unesite boju auta\n");
				getchar();
				scanf("%29[^\n]", &noviAuto.boja);

				printf("Unesite godinu proizvodnje\n");
				scanf(" %d", &noviAuto.godina_proizvodnje);
				printf("Unesite snagu motora auta (u kw)\n");
				scanf(" %d", &noviAuto.snaga_motora);
				printf("Unesite cijenu auta(u kn)\n");
				scanf(" %d", &noviAuto.cijena);
				printf("Unesite ID koji je razlicit od ostalih:\n");
				scanf(" %d", &noviAuto.id);

				brojAuta += 1;
				fwrite(&brojAuta, sizeof(int), 1, datoteka);
				rewind(datoteka);
				fseek(datoteka, 0, SEEK_END);
				fwrite(&noviAuto, sizeof(AUTO), 1, datoteka);
				fclose(datoteka);
			}
		}
	}
	else {
		sviAuti = ucitavanjeAuta(sviAuti);
		if (sviAuti == NULL) {
			printf("Nije moguce zauzeti memoriju\n ");
			printf("\nKraj programa\n");
			exit(EXIT_FAILURE);
		}
		else {
			datoteka = fopen(ime_dat, "rb+");
			if (datoteka == NULL) {
				printf("Nije moguce otvoriti datoteku auti.bin\n ");
				printf("\nKraj programa\n");
				exit(EXIT_FAILURE);
			}
			else {
				printf("Unesite ime modela\n");
				getchar();
				scanf("%29[^\n]", &noviAuto.model);
				printf("Unesite boju auta\n");
				getchar();
				scanf("%29[^\n]", &noviAuto.boja);
				printf("Unesite godinu proizvodnje\n");
				scanf(" %d", &noviAuto.godina_proizvodnje);
				printf("Unesite snagu motora auta (u kw)\n");
				scanf(" %d", &noviAuto.snaga_motora);
				printf("Unesite cijenu auta (u kn)\n");
				scanf(" %d", &noviAuto.cijena);
				do {
					flag = 1;
					printf("Unesite ID koji je razlicit od ostalih:\n");
					scanf(" %d", &noviAuto.id);
					for (i = 0; i < brojAuta; i++) {
						if (noviAuto.id == sviAuti[i].id) {
							flag = 0;
							break;
						}
					}
					i = 0;
				} while (flag == 0);
			}
		}
		brojAuta += 1;
		fwrite(&brojAuta, sizeof(int), 1, datoteka);
		rewind(datoteka);
		fseek(datoteka, 0, SEEK_END);
		fwrite(&noviAuto, sizeof(AUTO), 1, datoteka);
		fclose(datoteka);
	}
	free(sviAuti);
	printf("\nAuto unesen, stisnite bilo koju tipku za povratak u izbornik\n");
	_getch();
	system("cls");
}

void ispisAuta() {
	AUTO* auti = NULL;
	int brAuta = ucitavanjeBrojaAuta();
	auti = ucitavanjeAuta(auti);

	if (brAuta == 0) {
		printf("Trenutno nema auta za ispis.\n");
	}
	else {
		for (int i = 0; i < brAuta; i++) {
			printf("Model: %s\nBoja: %s\nGodina proizvodnje: %d ", (auti + i)->model, (auti + i)->boja, (auti + i)->godina_proizvodnje);
			printf("\nSnaga motora: %d \nCijena: %d \nID: %d", (auti + i)->snaga_motora, (auti + i)->cijena, (auti + i)->id);
			printf("\n\n");
		}
	}
}

bool editAutomobila(int tempId) {
	FILE* fajl = NULL;
	
	AUTO* sviAutomobili = NULL;

	AUTO* tempAutomobili = NULL;
	
	sviAutomobili = ucitavanjeAuta(sviAutomobili);

	
	if (sviAutomobili == NULL) {
		return false;
	}
	else {
		
		
		AUTO* tempAuto = NULL;
		
		int brElem = ucitavanjeBrojaAuta();


		for (int i = 0; i < brElem; i++) {
			
			int tmpId = sviAutomobili[i].id;

			if (tempId == tmpId) {
		
				tempAuto = &sviAutomobili[i];
		
				printf("Pronadjen auto sa ID-om: %d\n", tempId);
				
				printf("Model pronadjenog automobila: %s\n", (*tempAuto).model);

			
				break;
			}
		}

	
		if (tempAuto != NULL) {
	
			printf("\nPrethodna godina proizvodnje: %d", (*tempAuto).godina_proizvodnje);
			printf("\nUnesite novu godinu proizvodnje: ");
			scanf(" %d", &(*tempAuto).godina_proizvodnje);
			getchar();
			printf("Nova godina proizvodnje je: %d\n", (*tempAuto).godina_proizvodnje);

			printf("\nPrethodna boja automobila: %s", (*tempAuto).boja);
			printf("\nUnesite novu boju: ");
			scanf(" %[^\n]%*c", (*tempAuto).boja);
			printf("Nova boja je: %s\n", (*tempAuto).boja);

			printf("\nPrethodna cijena automobila: %d", (*tempAuto).cijena);
			printf("\nUnesite novu cijenu: ");
			scanf(" %d", &(*tempAuto).cijena);
			getchar();
			printf("Nova cijena je: %d\n", (*tempAuto).cijena);

			printf("\nPrethodni model automobila: %s", (*tempAuto).model);
			printf("\nUnesite novi model: ");
			scanf(" %[^\n]%*c", (*tempAuto).model);
			printf("Novi model je: %s\n", (*tempAuto).model);

			printf("\nPrethodna snaga motora: %d", (*tempAuto).snaga_motora);
			printf("\nUnesite novu snagu motora: ");
			scanf(" %d", &(*tempAuto).snaga_motora);
			getchar();
			printf("Nova snaga motora je: %d\n", (*tempAuto).snaga_motora);

		
			fajl = fopen("auti.bin", "w");

		
			if (fajl != NULL) {
				
				tempAutomobili = (AUTO*)calloc(brElem, sizeof(AUTO));

			
				if (tempAutomobili != NULL) {
			
					for (int i = 0; i < brElem; i++) {
						strcpy((tempAutomobili + i)->model, (sviAutomobili + i)->model);
						strcpy((tempAutomobili + i)->boja, (sviAutomobili + i)->boja);
						(tempAutomobili + i)->godina_proizvodnje = (sviAutomobili + i)->godina_proizvodnje;
						(tempAutomobili + i)->snaga_motora = (sviAutomobili + i)->snaga_motora;
						(tempAutomobili + i)->cijena = (sviAutomobili + i)->cijena;
						(tempAutomobili + i)->id = (sviAutomobili + i)->id;
						
					}
				}
				
				fwrite(&brElem, sizeof(int), 1, fajl);
				rewind(fajl);
				fseek(fajl, 0, SEEK_END);
				fwrite(tempAutomobili, sizeof(AUTO), brElem, fajl);
				fclose(fajl);

		
				free(sviAutomobili);
				free(tempAutomobili);
			}
		}
		else {
			return false;
		}
	}


	return true;
}


int brisanjeAuta(int id) {
	AUTO* auti = NULL;
	int brAuta = ucitavanjeBrojaAuta();
	int i = 0;
	int j = 0;
	int flag = 0;
	AUTO brisanje = { 0 };
	AUTO temp;
	FILE* datoteka = NULL;
	char* dat_ime = "auti.bin";
	AUTO* Pomoc;

	brisanje.id = id;

	if (brAuta == 0) {
		printf("Ne postoji niti jedan automobil u datoteci, ova funkcija se ne moze izvrsiti.\n");
		return 0;
	}
	else {
		auti = ucitavanjeAuta(auti);
		if (auti == NULL) {
			printf("Nije moguce procitati proizvode iz datoteke.\n");
			_getch();
			exit(EXIT_FAILURE);
		}
		else {
			for (i = 0; i < brAuta; i++) {
				if (brisanje.id == (auti + i)->id) {
					flag = 1;
					for (j = i; j < brAuta; j++) {
						if (j + 1 == brAuta) {
							break;
						}

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
			Pomoc = (AUTO*)calloc(brAuta - 1, sizeof(AUTO));
			if (Pomoc != NULL) {
				for (i = 0; i < brAuta - 1; i++) {
					strcpy((Pomoc + i)->model, (auti + i)->model);
					strcpy((Pomoc + i)->boja, (auti + i)->boja);
					(Pomoc + i)->godina_proizvodnje = (auti + i)->godina_proizvodnje;
					(Pomoc + i)->snaga_motora = (auti + i)->snaga_motora;
					(Pomoc + i)->cijena = (auti + i)->cijena;
					(Pomoc + i)->id = (auti + i)->id;
				}
			}
			else {
				flag = 0;
				exit(EXIT_FAILURE);
			}
			if (flag == 1) {
				datoteka = fopen(dat_ime, "w");
				if (datoteka != NULL) {
					brAuta = brAuta - 1;
					fwrite(&brAuta, sizeof(int), 1, datoteka);
					rewind(datoteka);
					fseek(datoteka, 4, SEEK_SET);
					fwrite(Pomoc, sizeof(AUTO), brAuta, datoteka);
					fclose(datoteka);
				}
			}
			free(Pomoc);
			free(auti);
			_getch();
		}
	}
	return flag;
}
