#include"maarittely.h"

int main()
{
	HLO henkilo[MAX_HLO];
	int valinta = 1;
	int lkm = 0;

	while (true)
	{
		valinta = Valikko();


		switch (valinta)
		{
		case 0:return 0;
		case 1:
			LisaaHenkilo(henkilo, &lkm);

			break;

		case 2:

			TulostaHenkilo(henkilo);
			break;

		case 3:

			TulostaKaikkiHenkilot(henkilo, lkm);
			break;

		case 4:
			PoistaTiedot(henkilo, &lkm);
			break;

		case 5:
			TallennaTiedostoon(henkilo, lkm);
			break;

		case 6:
			HaeTiedostosta(henkilo, &lkm);
			break;



		}

	}
}