#include <iostream>
#include <vector>
#include <limits>

#include "Ksiegarnia.h"

using namespace std;

vector <Ksiazka_Sportowa*> vKsiazka_Sportowa;
vector <Ksiazka_Kucharska*> vKsiazka_Kucharska;

void DodajNowaKsiazke(Menu_Wybor *x)
{
   x -> Uzupelnij_Dane();
}


int main()
{
	Menu m1;
	switch(m1.PobierzOpcje())
	{
		case 1:
		{
			Menu_NowaKsiazka n1;
			Menu_Wybor * wybor;
			switch(n1.PobierzOpcje())
			{
				case 1:
				{
					Ksiazka_Sportowa s1;
					wybor = &s1;
					DodajNowaKsiazke(wybor);
					break;
				}
				case 2:
				{
					Ksiazka_Kucharska k1;
					wybor = &k1;
					DodajNowaKsiazke(wybor);
					break;
				}
			}
			break;
		}
		default:
		{
			cout << endl << "Wybrano niewlasciwa opcje! Sprobuj ponownie...";
			main();
			break;
		}
	}
	
}

