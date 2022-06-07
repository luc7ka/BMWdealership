#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void izbornik() {
	int odabir;
	odabir = odabir_Korisnika();

	switch (odabir) {
	case 1:
		izbornik_Korisnik();
		break;
	case 2:
		izbornik_Admin();
		break;
	default:
		printf("\nKraj programa, stisnite bilo koju tipku za zavrsetak\n");
		_getch();
		break;
	}
	getch();

}
