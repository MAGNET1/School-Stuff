#include "Ksiazka_Sportowa.h"
#include "Wyjatki.h"

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


Ksiazka_Sportowa::Ksiazka_Sportowa(string n, string a, int x, int i, float c, string o, int y)
:Ksiazka(n, a, x, i, c)
{
	Skutecznosc_Treningow = o;
	ilosc_cwiczen = y;
}
Ksiazka_Sportowa::Ksiazka_Sportowa(Ksiazka_Sportowa &origin)
{
	nazwa = origin.nazwa+" [WYDANIE ROZSZERZONE]";
	autor = origin.autor;
	ilosc_stron = origin.ilosc_stron;
	ilosc_sztuk = origin.ilosc_sztuk;
	cena = origin.cena;
	Skutecznosc_Treningow = origin.Skutecznosc_Treningow;
	ilosc_cwiczen = origin.ilosc_cwiczen;
	this->Informacje();
	_getch();
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
	ilosc_cwiczen = input <int>();
	if(ilosc_cwiczen < 1)
	{
		throw IncorrectNumber("Ksiazka musi zawierac przynajmniej 1 trening!");
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