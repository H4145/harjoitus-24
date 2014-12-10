#include"maarittely.h"

int Valikko(void)
{
	int valinta;
	cout << "\nValikko\n\n";
	cout << "0. Lopetus\n";
	cout << "1. Uusi henkilo\n";
	cout << "2. Nayta henkilo\n";
	cout << "3. Nayta kaikki henkilot\n";
	cout << "4. Poista henkilon tiedot\n";
	cout << "5. Tallenna tiedot tiedostoon\n";
	cout << "6. Hae tiedot tiedostosta\n";
	cin >> valinta;
	return valinta;
}

void TulostaKaikkiHenkilot(HLO henkilo[], int lkm)
{

	for (int i = 0; i < lkm; i++)
	{
		cout << "\nNimi: " << henkilo[i].nimi << endl
			<< "Koulumatka: " << henkilo[i].matka << endl
			<< "Hatun koko: " << henkilo[i].hattu << endl << endl;
	}
}
void LisaaHenkilo(HLO p_henkilo[], int *lkm)
{
	cout << "Anna nimi: ";
	cin >> p_henkilo[*lkm].nimi;
	cout << "\nAnna koulumatka: ";
	cin >> p_henkilo[*lkm].matka;
	cout << "\nAnna hatun koko: ";
	cin >> p_henkilo[*lkm].hattu;
	(*lkm)++;
}

void TulostaHenkilo(HLO henkilo[])
{
	int nro;
	cout << "Tulostettavan henkilon numero? ";
	cin >> nro;
	if (nro > 10)
	{
		cout << " Danger: Overflow! ";
	}
	else
	{
		cout << "\n Nimi: " << henkilo[nro - 1].nimi << "\n Koulumatka: " << henkilo[nro - 1].matka << "\n Hatun koko: " << henkilo[nro - 1].hattu << endl;
	}
}

void PoistaTiedot(HLO p_henkilo[], int *lkm)
{
	int nro;
	cout << "\nValitse poistettava henkilö: ";
	cin >> nro;

	*p_henkilo[nro - 1].nimi = NULL;
	p_henkilo[nro - 1].matka = 0;
	p_henkilo[nro - 1].hattu = 0;

	for (nro; nro <= *lkm; nro++)
	{
		p_henkilo[nro - 1] = p_henkilo[nro];
	}

	(*lkm)--;
}

void TallennaTiedostoon(HLO henkilo[], int lkm)
{
	ofstream tiedosto("tiedot.txt");
	tiedosto << "Henkilon numero, Nimi, Matka, Hatun koko" << endl;

	for (int i = 0; (i < lkm); i++)
	{
		tiedosto << i + 1 << ',' << henkilo[i].nimi << ',' << henkilo[i].matka << ',' << henkilo[i].hattu << endl;
	}
}
void HaeTiedostosta(HLO henkilo[], int *lkm)
{
	char teksti[50];
	int i = 0;
	int nro;
	ifstream lue("tiedot.txt");
	lue.getline(teksti, 50);

	do
	{
		lue >> nro;
		lue.get();
		lue.get(henkilo[i].nimi, 10, ',');
		lue.get();
		lue >> henkilo[i].matka;
		lue.get();
		lue >> henkilo[i].hattu;
		lue.get();
		i++;
	} 
	while (lue.good());
	(*lkm) = i - 1;
	lue.close();

}

