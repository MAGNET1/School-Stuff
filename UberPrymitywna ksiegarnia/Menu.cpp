#include "Menu.h"

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