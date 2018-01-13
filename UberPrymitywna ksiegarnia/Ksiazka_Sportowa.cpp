#include "Ksiazka_Sportowa.h"

Ksiazka_Sportowa::Ksiazka_Sportowa(string n, string a, int x, int i, float c, string o, int y)
:Ksiazka(n, a, x, i, c)
{
	Skutecznosc_Treningow = o;
	ilosc_cwiczen = y;
}

Ksiazka_Sportowa::~Ksiazka_Sportowa()
{
	
}

void Ksiazka_Sportowa::Uzupelnij_Dane()
{
	string wyjatek;
	Ksiazka::Uzupelnij_Dane();
	cout << endl << "Opis skutecznosci treningow: ";
	getline(cin, Skutecznosc_Treningow);
	cout << endl << "Ilosc cwiczen: ";
	cin >> ilosc_cwiczen;
	if(ilosc_cwiczen < 1)
	{
		wyjatek = "Ksiazka musi zawierac przynajmniej 1 trening!";
		throw wyjatek;
	}
	
	ostringstream stringStream;
	stringStream << "1|"<<nazwa<<"|"<<autor<<"|"<<ilosc_stron<<"|"<<ilosc_sztuk<<"|"<<cena<<"|"<<Skutecznosc_Treningow<<"|"<<ilosc_cwiczen;
	string copyOfStr = stringStream.str();
	ZapiszDoPliku(copyOfStr, 1);
	
	system("cls");
	cout << endl << "Do rejestru dodano nowa ksiazke!" << endl << "Nazwa: " << nazwa << endl << "Autor: " << autor << endl  << "Cena: " << cena << endl << "Rodzaj: Ksiazka Sportowa" << endl;
	_getch();
}

void Ksiazka_Sportowa::SzybkieDodawanie(string line)
{
	Ksiazka::SzybkieDodawanie(line);
	Skutecznosc_Treningow = magic(line, '|', 6);
	ilosc_cwiczen = atoi(magic(line, '|', 7).c_str());
}

void Ksiazka_Sportowa::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Sportowa>" << endl;
}

void Ksiazka_Sportowa::Informacje()
{
	Ksiazka::Informacje();
	cout << "Skutecznosc treningow: " << Skutecznosc_Treningow << endl;
	cout << "Ilosc cwiczen: " << ilosc_cwiczen << endl;
}

void Ksiazka_Sportowa::Usun()
{
	delete this;
}