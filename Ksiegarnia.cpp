#include "Ksiegarnia.h"

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
	cin >> ilosc_przepisow;
	if(ilosc_przepisow < 1)
	{
		wyjatek = "Ksiazka musi zawierac jakies przepisy!";
		throw wyjatek;
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


Ksiazka_Psychologiczna::Ksiazka_Psychologiczna(string n, string a, int x, int i, float c, string p, string r, string dz)
:Ksiazka(n, a, x, i, c)
{
	poruszany_problem = p;
	rekomendacje_psychologow = r;
	dziedzina = dz;
}

Ksiazka_Psychologiczna::~Ksiazka_Psychologiczna()
{
	
}

void Ksiazka_Psychologiczna::Uzupelnij_Dane()
{
	Ksiazka::Uzupelnij_Dane();
	cout << endl << "Poruszany problem: ";
	getline(cin, poruszany_problem);
	cout << endl << "Rekomendacje psychologow: ";
	getline(cin, rekomendacje_psychologow);
	cout << endl << "Dziedzina: ";
	getline(cin, dziedzina);
	
	std::ostringstream stringStream;
	stringStream << "4|"<<nazwa<<"|"<<autor<<"|"<<ilosc_stron<<"|"<<ilosc_sztuk<<"|"<<cena<<"|"<<poruszany_problem<<"|"<<rekomendacje_psychologow<<"|"<<dziedzina;
	std::string copyOfStr = stringStream.str();
	ZapiszDoPliku(copyOfStr, 4);
	
	system("cls");
	cout << endl << "Do rejestru dodano nowa ksiazke!" << endl << "Nazwa: " << nazwa << endl << "Autor: " << autor << endl << "Cena: " << cena << endl << "Rodzaj: Ksiazka Psychologiczna" << endl;
	_getch();
}

void Ksiazka_Psychologiczna::SzybkieDodawanie(string line)
{
	Ksiazka::SzybkieDodawanie(line);
	poruszany_problem = magic(line, '|', 6);
	rekomendacje_psychologow = magic(line, '|', 7);
	dziedzina = magic(line, '|', 8);
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

Menu::Menu(int x)
{
	x=opt;
}

void Menu::MainMenu(float portfel)
{
	system("cls");
	cout << "Stan portfela: " << portfel << "zl" << endl;
	cout << "Co chcesz zrobic (0 - wyjscie):" << endl;
	cout << "1. Dodaj Ksiazke" << endl;
	cout << "2. Kup Ksiazke" << endl;
	cout << "3. Lista Ksiazek" << endl;
	cout << "Twoja wybor: ";
	cin >> opt;
	if(opt > 3 || opt < 0)
	{
		string wyjatek = "Niepoprawna opcja w menu!";
		throw wyjatek;
	}
}
void Menu::DodajKsiazkeMenu()
{
	system("cls");
	cout << "Wybierz rodzaj ksiazki: " << endl;
	cout << "1. Sportowa" << endl;
	cout << "2. Kucharska" << endl;
	cout << "3. Przygodowa" << endl;
	cout << "4. Psychologiczna" << endl;
	cout << "Twoj wybor: ";
	cin >> opt;
	if(opt > 4 || opt < 1)
	{
		string wyjatek = "Niepoprawna opcja!";
		throw wyjatek;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // na stdin zakolejkowany jest znak końca linii. Dzieki temu pomijam ten znak
}

Menu::~Menu()
{
	
}
void Menu::TakNieMenu()
{
	cout << "Czy chcesz kupic te ksiazke?" << endl;
	cout << "1. Tak, biore" << endl;
	cout << "2. Nie, zmienilem zdanie..." << endl;
	cout << "Twoj wybor: ";
	cin >> opt2;
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
void Ksiazka_Sportowa::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Sportowa>" << endl;
}
void Ksiazka_Kucharska::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Kucharska>" << endl;
}
void Ksiazka_Przygodowa::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Przygodowa>" << endl;
}
void Ksiazka_Psychologiczna::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Psychologiczna>" << endl;
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
void Ksiazka_Sportowa::Informacje()
{
	Ksiazka::Informacje();
	cout << "Skutecznosc treningow: " << Skutecznosc_Treningow << endl;
	cout << "Ilosc cwiczen: " << ilosc_cwiczen << endl;
}
void Ksiazka_Kucharska::Informacje()
{
	Ksiazka::Informacje();
	cout << "Historia kucharza: " << Historia_Kucharza << endl;
	cout << "Kategorie: " << kategorie << endl;
	cout << "Ilosc przepisow: " << ilosc_przepisow << endl;
}
void Ksiazka_Przygodowa::Informacje()
{
	Ksiazka::Informacje();
	cout << "Opis akcji: " << opis_akcji << endl;
	cout << "Czas akcji: " << czas_akcji << endl;
	cout << "Fabula: " << fabula << endl;
}
void Ksiazka_Psychologiczna::Informacje()
{
	Ksiazka::Informacje();
	cout << "Poruszany problem: " << poruszany_problem << endl;
	cout << "Rekomendacje psychologow: " << rekomendacje_psychologow << endl;
	cout << "Dziedzina: " << dziedzina << endl;
}
void Ksiazka::Usun()
{
	delete this;
}
void Ksiazka_Kucharska::Usun()
{
	delete this;
}
void Ksiazka_Sportowa::Usun()
{
	delete this;
}
void Ksiazka_Przygodowa::Usun()
{
	delete this;
}
void Ksiazka_Psychologiczna::Usun()
{
	delete this;
}
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