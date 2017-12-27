#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Menu
{
	int opt;
	
	public:
	Menu();
	~Menu();
	
	int PobierzOpcje()
	{
		return opt;
	}
};

class Menu_Wybor
{
public:
	virtual void Uzupelnij_Dane()=0;
};

class Menu_NowaKsiazka
{
	int opt;
	
public:
	Menu_NowaKsiazka();
	~Menu_NowaKsiazka();
	
	int PobierzOpcje()
	{
		return opt;
	}
};

class Ksiazka : public Menu_Wybor
{
	protected:
	string nazwa;
	string autor;
	int ilosc_stron;
	int ilosc_sztuk;
	
	int IleSztuk()
	{
		return ilosc_sztuk;
	}
	void SztukiUpdate(int x)
	{
		ilosc_sztuk = x;
	}
	
public:
	Ksiazka(string n="Brak Tytulu", string a="Brak Autora", int x=0, int i=0);
	~Ksiazka();
	void Uzupelnij_Dane();
};

class Ksiazka_Sportowa : public Ksiazka
{
	string Skutecznosc_Treningow;
	int ilosc_cwiczen;
	
public:
	Ksiazka_Sportowa(string n="", string a="", int x=0, int i=0, string o="Brak danych", int y=0)
	:Ksiazka(n, a, x, i)
	{
		Skutecznosc_Treningow = o;
		ilosc_cwiczen = y;
	}
	
	~Ksiazka_Sportowa();
	
	void Uzupelnij_Dane();
};

class Ksiazka_Kucharska : public Ksiazka
{
	string Historia_Kucharza;
	string kategorie;
	int ilosc_przepisow;
	
public:
	Ksiazka_Kucharska(string ="", string a="", int x=0, int i=0, string h="Nieznana", string k="Nieznane", int y=0);
	~Ksiazka_Kucharska();
	
	void Uzupelnij_Dane();
};