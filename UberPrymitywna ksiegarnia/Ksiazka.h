#pragma once

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