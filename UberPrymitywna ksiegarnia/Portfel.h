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