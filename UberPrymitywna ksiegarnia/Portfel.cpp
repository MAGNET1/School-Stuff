#include "Portfel.h"

Portfel::Portfel(float x)
{
	kasa = x;
}
void Portfel::Budzet()
{
	cout << "Podaj Twoj stan portfela: ";
	cin >> kasa;
	if(kasa < 0)
	{
		string wyjatek = "Nie mozna podawac ujemnych wartosci!";
		throw wyjatek;
	}
}
void Portfel::WyswietlStanKonta()
{
	cout << "Stan twojego portfela: " << kasa << "zl" << endl;
}