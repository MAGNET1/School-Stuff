#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "Ksiazka.h"

using namespace std;

class Ksiazka;

extern vector <Ksiazka*> vKsiazka;

string magic(const string&, const char, unsigned int);
void ZapiszDoPliku(string, int);
void PobierzKsiazki();

bool byAmount(Ksiazka*, Ksiazka*);
void SortujIlosc();
bool byName(Ksiazka*, Ksiazka*);
void SortujNazwa();

template <typename T>
T input();

int WyswietlListe();
void Wypelnij_Ksiazke(Ksiazka*);
void Polimorfizm();