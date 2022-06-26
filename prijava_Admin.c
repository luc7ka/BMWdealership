#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <stdbool.h>
#include <string.h>

bool prijava_Admin(ADMIN* admin_pok) {
	ADMIN unos;
	printf("Unesi korisnicko ime:\n  ");
	scanf("%s", &unos.korisnicko_ime);
	printf("Unesi lozinku:\n  ");
	scanf("%s", &unos.lozinka);
	if (strcmp(admin_pok->korisnicko_ime, unos.korisnicko_ime) == 0 && strcmp(admin_pok->lozinka, unos.lozinka) == 0)
		return true;
	else
		return false;
}
 
