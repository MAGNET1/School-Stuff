#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <memory>

#include "Ksiegarnia.h"

using namespace std;

vector <Ksiazka*> vKsiazka;

int WyswietlListe()
{
	unsigned int i;
	int x=0;
	system("cls");
	cout << "Wykaz ksiazek: " << endl << endl;
	for(i=0;i<vKsiazka.size();i++)
	{
		cout << ++x << ". ";
		vKsiazka[i]->InformacjePodstawowe();
	}
	return x;
}


int main()
{
	Portfel p;
	p.Budzet();
	Menu m1;
	while (1)
	{
		m1.MainMenu(p.StanPortfela());
		switch(m1.PobierzOpcje())
		{
			case 0:
			{
				unsigned int i;
				for(i=0;i<vKsiazka.size();i++)
				{
					Ksiazka * temp = vKsiazka[i];
					vKsiazka.erase(vKsiazka.begin()+i);
					//temp->Usun();
					delete temp;
				}
				break;
			}
			
			case 1:
			{
				m1.DodajKsiazkeMenu();
				int wybor = m1.PobierzOpcje();
				if(wybor == 0 || wybor > 2) // 
				{
					cout << endl << "Wybrano niewlasciwa opcje! Powrot do menu glownego...";
					_getch();
					break;
				}
				unique_ptr<Ksiazka*> temp2;
				vKsiazka.push_back(Ksiazka::StworzKsiazke(wybor));
				vKsiazka[vKsiazka.size()-1]->Uzupelnij_Dane();
				break;
			}
			case 2:
			{
				WyswietlListe();
				unsigned int wybor;
				cout << endl << "Ktora ksiazke chcialbys kupic (0 - menu glowne) ?" << endl << "Twoj wybor: ";
				cin >> wybor;
				if(wybor == 0 || wybor > vKsiazka.size())
				{
					cout << endl << "Powrot do menu glownego...";
					_getch();
					break;
				}
				vKsiazka[--wybor]->Informacje();
				cout << endl << endl;
				if(!vKsiazka[wybor]->IleSztuk())
				{
					cout << "Niestety, tej ksiazki nie ma juz w sklepie!";
					_getch();
					break;
				}
				int wybor2;
				cout << "Czy chcesz kupic te ksiazke?" << endl;
				cout << "1. Tak, biore" << endl;
				cout << "2. Nie, zmienilem zdanie..." << endl;
				cout << "Twoj wybor: ";
				cin >> wybor2;
				if(wybor2 != 1)
				{
					cout << endl << "Powrot do wykazu...";
					_getch();
					continue;
				}
				vKsiazka[wybor]->SztukiUpdate(vKsiazka[wybor]->IleSztuk()-1);
				cout << endl << "Pomyslnie dokonano zakupu ksiazki!";
				_getch();
				break;
			}
			case 3:
			{
				int x = WyswietlListe();
				cout << endl << "Ilosc ksiazek: " << x;
				_getch();
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

