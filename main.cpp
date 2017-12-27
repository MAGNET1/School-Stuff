#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>

#include "Ksiegarnia.h"

using namespace std;


int main()
{
	Menu m1;
	vector <Factory*> vKsiazka;
	while (1)
	{
		m1.MainMenu();
		switch(m1.PobierzOpcje())
		{
			case 0:	break;
			
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
				vKsiazka.push_back(Factory::StworzKsiazke(wybor));
				vKsiazka[vKsiazka.size()-1]->Uzupelnij_Dane();
				break;
			}
			//tutaj jeszcze case 2...
			case 3:
			{
				int i;
				int x=0;
				system("cls");
				cout << "Wykaz ksiazek: " << endl;
				for(i=0;i<vKsiazka.size();i++)
				{
					vKsiazka[i]->Informacje();
					x++;
				}
				cout << "Ilosc ksiazek: " << x;
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

