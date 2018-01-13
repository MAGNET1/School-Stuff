#include "Ksiazka_Kucharska.h"
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


Ksiazka_Kucharska::Ksiazka_Kucharska(string n, string a, int x, int i, float c, string h, string k, int y)
:Ksiazka(n, a, x, i, c)
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
	string wyjatek;
	Ksiazka::Uzupelnij_Dane();
	cout << endl << "Podaj historie kucharza: ";
	getline(cin, Historia_Kucharza);
	//cin >> Historia_Kucharza;
	cout << endl << "Podaj kategorie przepisow: ";
	getline(cin, kategorie);
	//cin >> kategorie;
	cout << endl << "Ilsoc przepisow: ";
	ilosc_przepisow = input<int>();
	if(ilosc_przepisow < 1)
	{
		throw IncorrectNumber("Ksiazka musi zawierac jakies przepisy!");
	}
	
	std::ostringstream stringStream;
	stringStream << "2|"<<nazwa<<"|"<<autor<<"|"<<ilosc_stron<<"|"<<ilosc_sztuk<<"|"<<cena<<"|"<<Historia_Kucharza<<"|"<<kategorie<<"|"<<ilosc_przepisow;
	std::string copyOfStr = stringStream.str();
	ZapiszDoPliku(copyOfStr, 2);
	
	system("cls");
	cout << endl << "Do rejestru dodano nowa ksiazke!" << endl << "Nazwa: " << nazwa << endl << "Autor: " << autor << endl << "Cena: " << cena << endl << "Rodzaj: Ksiazka Kucharska" << endl;
	_getch();
}

void Ksiazka_Kucharska::SzybkieDodawanie(string line)
{
	Ksiazka::SzybkieDodawanie(line);
	Historia_Kucharza = magic(line, '|', 6);
	kategorie = magic(line, '|', 7);
	ilosc_przepisow = atoi(magic(line, '|', 8).c_str());
}

void Ksiazka_Kucharska::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Kucharska>" << endl;
}
void Ksiazka_Kucharska::Informacje()
{
	Ksiazka::Informacje();
	cout << "Historia kucharza: " << Historia_Kucharza << endl;
	cout << "Kategorie: " << kategorie << endl;
	cout << "Ilosc przepisow: " << ilosc_przepisow << endl;
}
void Ksiazka_Kucharska::Usun()
{
	delete this;
}