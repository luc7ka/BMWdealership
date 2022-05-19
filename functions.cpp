#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int odabirNaIzborniku()
{
	int n;
	system("cls");
	printf("==============================================================\n");
	printf("=  Pretraživanje:                                            =\n");
	printf("======================================================================\n");
	printf("=  [1]  Model                                                        =\n");
	printf("=  [2]  Godina proizvodnje                                           =\n");
	printf("=  [3]  Cijena                                                       =\n");
	printf("=  [4]  Kilometraža                                                  =\n");
	printf("=  [0]  Izlaz                                                        =\n");
	printf("======================================================================\n");

	do {
		scanf("%d", &n);
		if (n < 0 || n > 4)
			printf("Pogresan unos.\nPokusajte ponovo.\n");
	} while (n < 0 || n > 4);

	return n;

		
