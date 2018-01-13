#include "Portfel.h"
#include "Wyjatki.h"
#include "funcs.h"

template <typename T>
T input()
{
	T d;
	string line;
	cin.clear();
	cin.sync();
	while(getline(cin, line))
	{
		stringstream sLine(line);
		if (sLine >> d && sLine.eof())	break;
		throw InputException("Nieprawidlowy typ danych. Sprobuj ponownie!");
	}
	return d;
}

Portfel::Portfel(float x)
{
	kasa = x;
}
void Portfel::Budzet()
{
	cout << "Podaj Twoj stan portfela: ";
	kasa = input<int>();
	if(kasa < 0)	throw NegativeNumber("Wartosc nie moze byc mniejsza od 0!");
}
void Portfel::WyswietlStanKonta()
{
	cout << "Stan twojego portfela: " << kasa << "zl" << endl;
}