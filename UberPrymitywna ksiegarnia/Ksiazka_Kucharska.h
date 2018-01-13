#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Ksiazka.h"
#include "funcs.h"

using namespace std;

void ZapiszDoPliku(string, int);
void PobierzKsiazki();

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