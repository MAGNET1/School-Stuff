#include "funcs.h"
#include "Wyjatki.h"

#include "Ksiazka.h"
#include "Ksiazka_Sportowa.h"
#include "Ksiazka_Kucharska.h"
#include "Ksiazka_Przygodowa.h"
#include "Ksiazka_Psychologiczna.h"

string magic( const std::string & str, const char ch, const unsigned int v )
{
    std::string ret = "";
    for( size_t i = 0, tmp = 0; i < str.size(); ++i ) {
        if( str[ i ] == ch ) {
            if( tmp > v ) break;
            else ++tmp;
            
        }
        else if( tmp == v ) ret += str[ i ];
        
    }
    return ret;
}
void ZapiszDoPliku(string data, int typ)
{
	ofstream p("Ksiazki.txt", ios::app);
	try
	{
		if(p.is_open())
		{
			p << data << "\n";
			cout << endl << "Pomyslnie zapisano ksiazke do bazy!";
			_getch();
		}
		else
		{
			throw FileError("Nie udalo sie zapisac ksiazki do bazy!");
		}
	}
	catch(FileError &e)
	{
		cout << e.getError();
		_getch();
	}
	p.close();
}
void PobierzKsiazki()
{
	string line;
	int x=0;
	
	ifstream p("Ksiazki.txt");
	try
	{
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
		else throw FileError("Nie udalo sie otworzyc pliku!"); 
	}
	catch(FileError &e)
	{
		cout << e.getError();
		_getch();
	}
  
  cout << "Z bazy pobrano " << x << " ksiazek!";
  _getch();
  system("cls");
}

bool byAmount(Ksiazka* element1, Ksiazka* element2)
{
	return element1->IleSztuk() < element2->IleSztuk();
}
void SortujIlosc()
{
	sort(vKsiazka.begin(), vKsiazka.end(), byAmount);
}
bool byName(Ksiazka* element1, Ksiazka* element2)
{
	return element1->JakaNazwa() < element2->JakaNazwa();
}
void SortujNazwa()
{
	sort(vKsiazka.begin(), vKsiazka.end(), byName);
}

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

void Wypelnij_Ksiazke(Ksiazka * p)
{
	p->Uzupelnij_Dane();
	p->Informacje();
}

void Polimorfizm()
{
	int XX;
	cout << "Zaprezentowac polimorfizm i konstruktor kopiujacy? 1 - tak, inne - nie... ";
	cin >> XX;
	if(XX != 1)	return;
	
	Ksiazka * p;
	
	Ksiazka_Sportowa x;
	Ksiazka_Kucharska y;
	Ksiazka_Przygodowa z;
	
	p = &x;
	Wypelnij_Ksiazke(p);
	Ksiazka_Sportowa copy(x);
	
	p = &y;
	Wypelnij_Ksiazke(p);
}