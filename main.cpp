#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "Ksiegarnia.h"

using namespace std;

vector <Ksiazka*> vKsiazka;

#include "funcs.h"

void ZapiszDoPliku(string data, int typ)
{
	ofstream p("Ksiazki.txt", ios::app);
	if(p.is_open())
	{
		p << data << "\n";
		cout << endl << "Pomyslnie zapisano ksiazke do bazy!";
		_getch();
	}
	else
	{
		cout << "Nie udalo sie zapisac ksiazki do bazy!";
		_getch();
	}
}
void PobierzKsiazki()
{
	string line;
	int x=0;
	
	ifstream p("Ksiazki.txt");
	
	if(p.is_open())
	{
		while(getline(p, line))
		{
			x++;
			int id = vKsiazka.size();
			int x = atoi(magic(line, '|', 0).c_str()); //id rodzaju ksiazki
			vKsiazka.push_back(Ksiazka::StworzKsiazke(x));
			vKsiazka[id]->SzybkieDodawanie(line);
			
		}
		p.close();
	}
  else cout << "Unable to open file"; 
  
  cout << "Z bazy pobrano " << x << " ksiazek!";
  _getch();
  system("cls");
}

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
	PobierzKsiazki();
	cout << fixed << setprecision(2);
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
					vKsiazka[i]->Usun();
					vKsiazka.erase(vKsiazka.begin()+i);
				}
				break;
			}
			
			case 1:
			{
				m1.DodajKsiazkeMenu();
				int wybor = m1.PobierzOpcje();
				if(wybor == 0 || wybor > 4) // 
				{
					cout << endl << "Wybrano niewlasciwa opcje! Powrot do menu glownego...";
					_getch();
					break;
				}
				vKsiazka.push_back(Ksiazka::StworzKsiazke(wybor));
				vKsiazka[vKsiazka.size()-1]->Uzupelnij_Dane();
				break;
			}
			case 2:
			{
				if(!vKsiazka.size())
				{
					system("cls");
					cout << "Brak ksiazek! Wroc tu pozniej!";
					_getch();
					break;
				}
				WyswietlListe();
				unsigned int wybor;
				cout << endl << "Stan portfela: " << p.StanPortfela() << endl << "Ktora ksiazke chcialbys kupic (0 - menu glowne) ?" << endl << "Twoj wybor: ";
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
				if(vKsiazka[wybor]->CenaKsiazki() > p.StanPortfela())
				{
					cout << "Nie masz wystarczajaco duzo pieniedzy na zakup!";
					_getch();
					break;
				}
				m1.TakNieMenu();
				if(m1.PobierzOpcjeTakNie() != 1)
				{
					cout << endl << "Powrot do wykazu...";
					_getch();
					continue;
				}
				vKsiazka[wybor]->SztukiUpdate(vKsiazka[wybor]->IleSztuk()-1);
				p.PortfelUpdate(p.StanPortfela()-vKsiazka[wybor]->CenaKsiazki());
				cout << endl << "Pomyslnie dokonano zakupu ksiazki!";
				_getch();
				break;
			}
			case 3:
			{
				if(!vKsiazka.size())
				{
					system("cls");
					cout << "Brak ksiazek! Wroc tu pozniej!";
					_getch();
					break;
				}
				int wybor=1;
				while(1)
				{
					cout << endl << "Ilosc ksiazek: " << vKsiazka.size();
					WyswietlListe();
					cout << "Aby przeczytac o ksiazce, wybierz jej numer. Menu glowne - 0" << endl;
					cout << "Twoj wybor: ";
					cin >> wybor;
					if(wybor == 0)	break;
					vKsiazka[--wybor]->Informacje();
					_getch();
				}
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
