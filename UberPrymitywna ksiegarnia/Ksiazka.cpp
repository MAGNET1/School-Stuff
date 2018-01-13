#include "Ksiazka.h"
#include "Ksiazka_Sportowa.h"
#include "Ksiazka_Kucharska.h"
#include "Ksiazka_Przygodowa.h"
#include "Ksiazka_Psychologiczna.h"

Ksiazka::Ksiazka(string n, string a, int x, int i, float c)
{
	nazwa = n;
	autor = a;
	ilosc_stron = x;
	ilosc_sztuk = i;
	cena = c;
}
Ksiazka::~Ksiazka()
{
	
}

void Ksiazka::Uzupelnij_Dane()
{
	string wyjatek;
	system("cls");
	cout << "Podaj nazwe ksiazki: ";
	getline(cin, nazwa);
	cout << endl <<"Podaj autora: ";
	getline(cin, autor);
	cout << endl << "Podaj ilosc stron: ";
	cin >> ilosc_stron;
	if(ilosc_stron < 1)
	{
		wyjatek= "Niepoprawna ilosc stron!";
		throw wyjatek;
	}
	cout << endl << "Ilosc sztuk: ";
	cin >> ilosc_sztuk;
	if(ilosc_sztuk < 0)
	{
		wyjatek = "Niepoprawna ilosc sztuk!";
		throw wyjatek;
	}
	cout << endl << "Podaj cene: ";
	cin >> cena;
	if(cena < 0)
	{
		wyjatek = "Niepoprawna cena!";
		throw wyjatek;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // na stdin zakolejkowany jest znak końca linii. Dzieki temu pomijam ten znak
}

void Ksiazka::SzybkieDodawanie(string line)
{
	nazwa = magic(line, '|', 1);
	autor = magic(line, '|', 2);
	ilosc_stron = atoi(magic(line, '|', 3).c_str());
	ilosc_sztuk = atoi(magic(line, '|', 4).c_str());
	cena = atof(magic(line, '|', 5).c_str());
}
Ksiazka * Ksiazka::StworzKsiazke(int wybor)
{
	switch(wybor)
	{
		case 1:
		{
			return new Ksiazka_Sportowa;
			break;
		}
		case 2:
		{
			return new Ksiazka_Kucharska;
			break;
		}
		case 3:
		{
			return new Ksiazka_Przygodowa;
			break;
		}
		case 4:
		{
			return new Ksiazka_Psychologiczna;
			break;
		}
	}
	return new Ksiazka;
}
void Ksiazka::InformacjePodstawowe()
{
	cout << nazwa << " [" << autor << "] (" << ilosc_sztuk << ")";
}

void Ksiazka::Informacje()
{
	cout << endl << "Informacje o ksiazce:" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Autor: " << autor << endl;
	cout << "Ilosc stron: " << ilosc_stron << endl;
	cout << "Ilosc sztuk: " << ilosc_sztuk << endl;
	cout << "Cena: " << cena << endl;
}
void Ksiazka::Usun()
{
	delete this;
}