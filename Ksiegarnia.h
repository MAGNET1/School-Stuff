#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "funcs.h"

using namespace std;

void ZapiszDoPliku(string, int);
void PobierzKsiazki();

class Portfel
{
	int kasa;
	
public:
	Portfel(float=0);
	float StanPortfela()	{return kasa;}
	void PortfelUpdate(float i)	{kasa=i;}
	void Budzet();
	void WyswietlStanKonta();
};

class Menu
{
	int opt;
	int opt2;
	
	public:
	Menu(int x=0);
	~Menu();
	
	int PobierzOpcje()
	{
		return opt;
	}
	int PobierzOpcjeTakNie()
	{
		return opt2;
	}
	void MainMenu(float);
	void DodajKsiazkeMenu();
	void TakNieMenu();
};

class Ksiazka
{
	protected:
	string nazwa;
	string autor;
	int ilosc_stron;
	int ilosc_sztuk;
	float cena;
	
public:
	Ksiazka(string n="Brak Tytulu", string a="Brak Autora", int x=0, int i=0, float c=0.0);
	virtual ~Ksiazka();
	virtual void Uzupelnij_Dane();
	virtual void Informacje();
	virtual void InformacjePodstawowe();
	virtual void Usun();
	virtual void SzybkieDodawanie(string);
	static Ksiazka * StworzKsiazke(int wybor);
	
	int IleSztuk()
	{
		return ilosc_sztuk;
	}
	void SztukiUpdate(int x)
	{
		ilosc_sztuk = x;
	}
	float CenaKsiazki()
	{
		return cena;
	}
};

class Ksiazka_Sportowa : public Ksiazka
{
	string Skutecznosc_Treningow;
	int ilosc_cwiczen;
	
public:
	Ksiazka_Sportowa(string n="", string a="", int x=0, int i=0, float c=0.0, string o="Brak danych", int y=0);
	
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
	void SzybkieDodawanie(string);
};

class Ksiazka_Kucharska : public Ksiazka
{
	string Historia_Kucharza;
	string kategorie;
	int ilosc_przepisow;
	
public:
	Ksiazka_Kucharska(string n="", string a="", int x=0, int i=0, float c=0.0, string h="Nieznana", string k="Nieznane", int y=0);
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
	void SzybkieDodawanie(string);
};
class Ksiazka_Przygodowa : public Ksiazka
{
	string opis_akcji;
	string czas_akcji;
	string fabula;
	
public:
	Ksiazka_Przygodowa(string n="", string a="", int x=0, int i=0, float c=0.0, string o="", string cz="", string f="");
	~Ksiazka_Przygodowa();
	
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
	void SzybkieDodawanie(string);
};

class Ksiazka_Psychologiczna : public Ksiazka
{
	string poruszany_problem;
	string rekomendacje_psychologow;
	string dziedzina;
	
public:
	Ksiazka_Psychologiczna(string ="", string a="", int x=0, int i=0, float c=0.0, string p="", string r="", string dz="");
	~Ksiazka_Psychologiczna();
	
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
	void SzybkieDodawanie(string);
};