#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

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
