#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Portfel
{
	int kasa;
	
public:
	Portfel(int=0);
	float StanPortfela()	{return kasa;}
	void PortfelUpdate(int i)	{kasa=i;}
	void Budzet();
	void WyswietlStanKonta();
};

class Menu
{
	int opt;
	
	public:
	Menu(int x=0);
	~Menu();
	
	int PobierzOpcje()
	{
		return opt;
	}
	void MainMenu(float);
	void DodajKsiazkeMenu();
};

class Ksiazka
{
	protected:
	string nazwa;
	string autor;
	int ilosc_stron;
	int ilosc_sztuk;
	
public:
	Ksiazka(string n="Brak Tytulu", string a="Brak Autora", int x=0, int i=0);
	~Ksiazka();
	virtual void Uzupelnij_Dane();
	virtual void Informacje();
	virtual void InformacjePodstawowe();
	virtual void Usun();
	static Ksiazka * StworzKsiazke(int wybor);
	
	int IleSztuk()
	{
		return ilosc_sztuk;
	}
	void SztukiUpdate(int x)
	{
		ilosc_sztuk = x;
	}
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
	
	int IleSztuk()
	{
		return ilosc_sztuk;
	}
	void SztukiUpdate(int x)
	{
		ilosc_sztuk = x;
	}
	
	~Ksiazka_Sportowa();
	
	void Uzupelnij_Dane();
	void Informacje();
	void InformacjePodstawowe();
	void Usun();
};

class Ksiazka_Kucharska : public Ksiazka
{
	string Historia_Kucharza;
	string kategorie;
	int ilosc_przepisow;
	
public:
	Ksiazka_Kucharska(string ="", string a="", int x=0, int i=0, string h="Nieznana", string k="Nieznane", int y=0);
	~Ksiazka_Kucharska();
	
	int IleSztuk()
	{
		return ilosc_sztuk;
	}
	void SztukiUpdate(int x)
	{
		ilosc_sztuk = x;
	}
	
	void Uzupelnij_Dane();
	void Informacje();
	void InformacjePodstawowe();
	void Usun();
};