#include "Ksiazka_Przygodowa.h"
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


Ksiazka_Przygodowa::Ksiazka_Przygodowa(string n, string a, int x, int i, float c, string o, string cz, string f)
:Ksiazka(n, a, x, i, c)
{
	opis_akcji = o;
	czas_akcji = cz;
	fabula = f;
}

Ksiazka_Przygodowa::~Ksiazka_Przygodowa()
{
	
}

void Ksiazka_Przygodowa::Uzupelnij_Dane()
{
	Ksiazka::Uzupelnij_Dane();
	cout << endl << "Opis akcji: ";
	getline(cin, opis_akcji);
	cout << endl << "Czas akcji: ";
	getline(cin, czas_akcji);
	cout << endl << "Fabula: ";
	getline(cin, fabula);
	
	std::ostringstream stringStream;
	stringStream << "3|"<<nazwa<<"|"<<autor<<"|"<<ilosc_stron<<"|"<<ilosc_sztuk<<"|"<<cena<<"|"<<opis_akcji<<"|"<<czas_akcji<<"|"<<fabula;
	std::string copyOfStr = stringStream.str();
	ZapiszDoPliku(copyOfStr, 3);
	
	system("cls");
	cout << endl << "Do rejestru dodano nowa ksiazke!" << endl << "Nazwa: " << nazwa << endl << "Autor: " << autor << endl << "Cena: " << cena << endl << "Rodzaj: Ksiazka Przygodowa" << endl;
	_getch();
}

void Ksiazka_Przygodowa::SzybkieDodawanie(string line)
{
	Ksiazka::SzybkieDodawanie(line);
	opis_akcji = magic(line, '|', 6);
	czas_akcji = magic(line, '|', 7);
	fabula = magic(line, '|', 8);
}

void Ksiazka_Przygodowa::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Przygodowa>" << endl;
}
void Ksiazka_Przygodowa::Informacje()
{
	Ksiazka::Informacje();
	cout << "Opis akcji: " << opis_akcji << endl;
	cout << "Czas akcji: " << czas_akcji << endl;
	cout << "Fabula: " << fabula << endl;
}
void Ksiazka_Przygodowa::Usun()
{
	delete this;
}