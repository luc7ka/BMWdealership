#ifndef HEADER_H
#define HEADER_H
#include <stdbool.h>

typedef struct auti {
	char model[30];
	char boja[30];
	int godina_proizvodnje;
	int snaga_motora;
	int cijena;
	int id;
}AUTO;

typedef struct admin {
	char korisnicko_ime[20];
	char lozinka[15];
	int id;
}ADMIN;



void izbornik();
int odabir_Korisnika();
void izbornik_Admin();
bool prijava_Admin(ADMIN* admin_pok);
void unosNovogAuta();
int ucitavanjeBrojaAuta();
void kreiranjeDatotekeAuti();
AUTO* ucitavanjeAuta(AUTO* automobil);
void ispisAuta();
int krajPrograma(void);
int brisanjeAuta(int id);

void izbornik_Korisnik();
void kupnjaAuta();




#endif
