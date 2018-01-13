#include "Menu.h"
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
	cout << "4. Sortuj Ksiazki" << endl;
	cout << "Twoja wybor: ";
	opt = input<int>();
	
	if(opt > 4 || opt < 0)
	{
		throw IncorrectNumber("Wybrano niepoprawna opcje z menu!");
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
	opt = input<int>();
	if(opt > 4 || opt < 1)
	{
		throw IncorrectNumber("Niepoprawna opcja!");
	}
}

void Menu::SortujMenu()
{
	system("cls");
	cout << "Jak chcesz posortowac ksiazki:" << endl;
	cout << "1. Sortuj wedlug nazwy" << endl;
	cout << "2. Sortuj wedlug ilosc sztuk" << endl;
	cout << "Twoj wybor: ";
	opt = input<int>();
	if(opt > 2 || opt < 1)
	{
		throw IncorrectNumber("Niepoprawna opcja!");
	}
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // na stdin zakolejkowany jest znak końca linii. Dzieki temu pomijam ten znak
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
	opt2 = input<int>();
	if(opt2 > 2 || opt2 < 1)
	{
		throw IncorrectNumber("Niepoprawna opcja z menu!");
	}
}