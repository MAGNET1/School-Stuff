#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

#include "Ksiazka.h"
#include "Ksiazka_Sportowa.h"
#include "Ksiazka_Kucharska.h"
#include "Ksiazka_Przygodowa.h"
#include "Ksiazka_Psychologiczna.h"
#include "Menu.h"
#include "Portfel.h"
#include "Wyjatki.h"
vector <Ksiazka*> vKsiazka;
#include "funcs.h"

void CzyscWektor()
{
	unsigned int i;
	for(i=0;i<vKsiazka.size();i++)
	{
		vKsiazka[i]->Usun();
		vKsiazka.erase(vKsiazka.begin()+i);
	}
}
void DodajKsiazke(Menu m1)
{
	
	try
	{
		m1.DodajKsiazkeMenu();
	}
	catch(InputException &e)
	{
		cout << e.getError();
		_getch();
		DodajKsiazke(m1);
		return;
	}
	catch(IncorrectNumber &e)
	{
		cout << e.getError();
		_getch();
		DodajKsiazke(m1);
		return;
	}
	
	int wybor = m1.PobierzOpcje();
	
	vKsiazka.push_back(Ksiazka::StworzKsiazke(wybor));
	while(1)
	{
		try
		{
			vKsiazka[vKsiazka.size()-1]->Uzupelnij_Dane();
		}
		catch(InputException &e)
		{
			cout << e.getError();
			_getch();
			continue;
		}
		catch(NegativeNumber &e)
		{
			cout << e.getError();
			_getch();
			continue;
		}
		break;
	}
}
void KupKsiazke(Portfel &p, Menu m1)
{
	try
	{
		if(!vKsiazka.size())
		{
			throw IncorrectNumber("Brak ksiazek! Wroc tu pozniej!");
		}
	}
	catch(IncorrectNumber &e)
	{
		cout << e.getError();
		_getch();
		system("cls");
		return;
	}
	WyswietlListe();
	unsigned int wybor;
	cout << endl << "Stan portfela: " << p.StanPortfela() << endl << "Ktora ksiazke chcialbys kupic (0 - menu glowne) ?" << endl << "Twoj wybor: ";
	try
	{
		wybor = input<int>();
		if(wybor == 0 || wybor > vKsiazka.size())
			throw IncorrectNumber("Wybrano niewlasciwa opcje!");
	}
	catch(InputException &e)
	{
		cout << e.getError();
		_getch();
		KupKsiazke(p, m1);
		return;
	}
	catch(IncorrectNumber &e)
	{
		cout << e.getError();
		_getch();
		KupKsiazke(p, m1);
		return;
	}
	
	vKsiazka[--wybor]->Informacje();
	cout << endl << endl;
	try
	{
		if(!vKsiazka[wybor]->IleSztuk())
		{
			throw NoBooks("Niestety, tej ksiazki nie ma juz w sklepie!");
		}
		if(vKsiazka[wybor]->CenaKsiazki() > p.StanPortfela())
		{
			throw NoMoney("Nie masz wystarczajaco duzo pieniedzy na zakup!");
		}
		m1.TakNieMenu();
		if(m1.PobierzOpcjeTakNie() != 1)
		{
			cout << endl << "Powrot do wykazu...";
			_getch();
			KupKsiazke(p, m1);
			return;
		}
	}
	catch(InputException &e)
	{
		cout << e.getError();
		_getch();
		KupKsiazke(p, m1);
	}
	catch(IncorrectNumber &e)
	{
		cout << e.getError();
		_getch();
		return;
	}
	catch(NoMoney &e)
	{
		cout << e.getError();
		_getch();
		return;
	}
	catch(NoBooks &e)
	{
		cout << e.getError();
		_getch();
		return;
	}
	
	vKsiazka[wybor]->SztukiUpdate(vKsiazka[wybor]->IleSztuk()-1);
	p.PortfelUpdate(p.StanPortfela()-vKsiazka[wybor]->CenaKsiazki());
	cout << endl << "Pomyslnie dokonano zakupu ksiazki!";
	_getch();
}
void WyswietlKsiazki()
{
	try
	{
		if(!vKsiazka.size())
		{
			throw NoBooks("Brak ksiazek! Wroc tu pozniej!");
		}
	}
	catch(NoBooks &e)
	{
		system("cls");
		cout << e.getError();
		_getch();
		return;
	}
	unsigned int wybor=1;
	while(1)
	{
		cout << endl << "Ilosc ksiazek: " << vKsiazka.size();
		WyswietlListe();
		cout << "Aby przeczytac o ksiazce, wybierz jej numer. Menu glowne - 0" << endl;
		cout << "Twoj wybor: ";
		try
		{
			wybor = input<int>();
			if(wybor > vKsiazka.size() || wybor < 0)
				throw IncorrectNumber("Niepoprawna opcja. Sprobuj ponownie!");
		}
		catch(InputException &e)
		{
			cout << e.getError();
			_getch();
			continue;
		}
		catch(IncorrectNumber &e)
		{
			cout << e.getError();
			_getch();
			continue;
		}
		if(wybor == 0)	break;
		vKsiazka[--wybor]->Informacje();
		_getch();
	}
}
void SortujKsiazki(Menu m1)
{
	try
	{
		m1.SortujMenu();
	}
	catch(InputException &e)
	{
		cout << e.getError();
		_getch();
		SortujKsiazki(m1);
		return;
	}
	catch(IncorrectNumber &e)
	{
		cout << e.getError();
		SortujKsiazki(m1);
		_getch();
	}
				
	if(m1.PobierzOpcje() == 1)
	{
		SortujNazwa();
	}
	else
	{
		SortujIlosc();
	}
	printf("Posortowano!");
	_getch();
}
void _Menu()
{
	Portfel p;
	try
	{
		p.Budzet();
	}
	catch(InputException &e)
	{
		cout << e.getError();
		_getch();
		system("cls");
		_Menu();
		return;
	}
	catch(NegativeNumber &e)
	{
		cout << e.getError();
		_getch();
		system("cls");
		_Menu();
		return;
	}
	Menu m1;
	while (1)
	{
		try
		{
			m1.MainMenu(p.StanPortfela());
		}
		catch(InputException &e)
		{
			cout << e.getError();
			_getch();
			continue;
		}
		catch(IncorrectNumber &e)
		{
			cout << e.getError();
			_getch();
			continue;
		}
		
		switch(m1.PobierzOpcje())
		{
			case 0:
			{
				CzyscWektor();
				break;
			}
			case 1:
			{
				DodajKsiazke(m1);
				break;
			}
			case 2:
			{
				KupKsiazke(p, m1);
				break;
			}
			case 3:
			{
				WyswietlKsiazki();
				break;
			}
			case 4:
			{
				SortujKsiazki(m1);
				break;
			}
			default:
			{
				cout << endl << "Wybrano niewlasciwa opcje! Sprobuj ponownie...";
				_getch();
				break;
			}
		}
		if(m1.PobierzOpcje() == 0)	break;
	}
	
}


int main()
{
	PobierzKsiazki();
	cout << fixed << setprecision(2);
	Polimorfizm();
	_Menu();
	return 0;
}