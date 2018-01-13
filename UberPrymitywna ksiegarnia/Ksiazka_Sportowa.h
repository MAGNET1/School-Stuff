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

class Ksiazka_Sportowa : public Ksiazka
{
	string Skutecznosc_Treningow;
	int ilosc_cwiczen;
	
public:
	Ksiazka_Sportowa(string n="", string a="", int x=0, int i=0, float c=0.0, string o="Brak danych", int y=0);
	//kopiujacy
	Ksiazka_Sportowa(Ksiazka_Sportowa &origin);
	
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