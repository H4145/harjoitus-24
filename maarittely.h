/*
Eetu Salo

Harjoitus 24 (Palautus vko 50)
Muuta harjoitusta 22 niin, etta valikko nayttaa seuraavalta:

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta henkilo
3 Nayta kaikki henkilot
4 Poista henkilon tiedot
5 Tallenna tiedot tiedostoon
6 Hae tiedot tiedostosta


ja toteuta valikossa näkyvät toiminnot.

Valitse haluamasi tallennusformaatti.



*/



#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct HLO
{
	char nimi[32];
	float matka;
	int hattu;
};
const int MAX_HLO = 10;

int Valikko(void);
void TulostaKaikkiHenkilot(HLO[], int lkm);
void LisaaHenkilo(HLO[], int *lkm);
void TulostaHenkilo(HLO henkilo[]);
void PoistaTiedot(HLO henkilo[], int *lkm);
void TallennaTiedostoon(HLO henkilo[], int lkm);
void HaeTiedostosta(HLO[], int *lkm);



