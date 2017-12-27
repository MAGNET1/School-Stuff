#include "Ksiegarnia.h"

Ksiazka::Ksiazka(string n, string a, int x, int i)
{
	nazwa = n;
	autor = a;
	ilosc_stron = x;
	ilosc_sztuk = i;
}

Ksiazka::~Ksiazka()
{
	
}

void Ksiazka::Uzupelnij_Dane()
{
	cout << "Podaj nazwe ksiazki: ";
	getline(cin, nazwa);
	cout << endl <<"Podaj autora: ";
	getline(cin, autor);
	cout << endl << "Podaj ilosc stron: ";
	cin >> ilosc_stron;
	cout << endl << "Ilosc sztuk: ";
	cin >> ilosc_sztuk;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // na stdin zakolejkowany jest znak końca linii. Dzieki temu pomijam ten znak
}

Ksiazka_Sportowa::~Ksiazka_Sportowa()
{
	
}

void Ksiazka_Sportowa::Uzupelnij_Dane()
{
	Ksiazka::Uzupelnij_Dane();
	cout << endl << "Opis skutecznosci treningow: ";
	getline(cin, Skutecznosc_Treningow);
	cout << endl << "Ilosc cwiczen: ";
	cin >> ilosc_cwiczen;
	
	cout << endl << "Do rejestru dodano nowa ksiazke!" << endl << "Nazwa: " << nazwa << endl << "Autor: " << autor << endl << "Rodzaj: Ksiazka Sportowa" << endl;
}

Ksiazka_Kucharska::Ksiazka_Kucharska(string n, string a, int x, int i, string h, string k, int y)
:Ksiazka(n, a, x, i)
{
	Historia_Kucharza = h;
	kategorie = k;
	ilosc_przepisow = y;
}

Ksiazka_Kucharska::~Ksiazka_Kucharska()
{
	
}

void Ksiazka_Kucharska::Uzupelnij_Dane()
{
	Ksiazka::Uzupelnij_Dane();
	cout << endl << "Podaj historie kucharza: ";
	getline(cin, Historia_Kucharza);
	//cin >> Historia_Kucharza;
	cout << endl << "Podaj kategorie przepisow: ";
	getline(cin, kategorie);
	//cin >> kategorie;
	cout << endl << "Ilsoc przepisow: ";
	cin >> ilosc_przepisow;
	
	cout << endl << "Do rejestru dodano nowa ksiazke!" << endl << "Nazwa: " << nazwa << endl << "Autor: " << autor << endl << "Rodzaj: Ksiazka Kucharska" << endl;
}

Menu::Menu()
{
	cout << "Co chcesz zrobic:" << endl;
	cout << "1. Dodaj Ksiazke" << endl;
	cout << "2. Kup Ksiazke" << endl;
	cout << "3. Lista Ksiazek" << endl;
	cout << "Twoja wybor: ";
	cin >> opt;
}

Menu::~Menu()
{
	
}

Menu_NowaKsiazka::Menu_NowaKsiazka()
{
	cout << "Wybierz rodzaj ksiazki: " << endl;
	cout << "1. Sportowa" << endl;
	cout << "2. Kucharska" << endl;
	cout << "Twoj wybor: ";
	cin >> opt;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // na stdin zakolejkowany jest znak końca linii. Dzieki temu pomijam ten znak
}
Menu_NowaKsiazka::~Menu_NowaKsiazka()
{
	
}