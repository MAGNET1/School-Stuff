#include "Ksiazka_Psychologiczna.h"

Ksiazka_Psychologiczna::Ksiazka_Psychologiczna(string n, string a, int x, int i, float c, string p, string r, string dz)
:Ksiazka(n, a, x, i, c)
{
	poruszany_problem = p;
	rekomendacje_psychologow = r;
	dziedzina = dz;
}

Ksiazka_Psychologiczna::~Ksiazka_Psychologiczna()
{
	
}

void Ksiazka_Psychologiczna::Uzupelnij_Dane()
{
	Ksiazka::Uzupelnij_Dane();
	cout << endl << "Poruszany problem: ";
	getline(cin, poruszany_problem);
	cout << endl << "Rekomendacje psychologow: ";
	getline(cin, rekomendacje_psychologow);
	cout << endl << "Dziedzina: ";
	getline(cin, dziedzina);
	
	std::ostringstream stringStream;
	stringStream << "4|"<<nazwa<<"|"<<autor<<"|"<<ilosc_stron<<"|"<<ilosc_sztuk<<"|"<<cena<<"|"<<poruszany_problem<<"|"<<rekomendacje_psychologow<<"|"<<dziedzina;
	std::string copyOfStr = stringStream.str();
	ZapiszDoPliku(copyOfStr, 4);
	
	system("cls");
	cout << endl << "Do rejestru dodano nowa ksiazke!" << endl << "Nazwa: " << nazwa << endl << "Autor: " << autor << endl << "Cena: " << cena << endl << "Rodzaj: Ksiazka Psychologiczna" << endl;
	_getch();
}

void Ksiazka_Psychologiczna::SzybkieDodawanie(string line)
{
	Ksiazka::SzybkieDodawanie(line);
	poruszany_problem = magic(line, '|', 6);
	rekomendacje_psychologow = magic(line, '|', 7);
	dziedzina = magic(line, '|', 8);
}

void Ksiazka_Psychologiczna::InformacjePodstawowe()
{
	Ksiazka::InformacjePodstawowe();
	cout << " <Ksiazka Psychologiczna>" << endl;
}

void Ksiazka_Psychologiczna::Informacje()
{
	Ksiazka::Informacje();
	cout << "Poruszany problem: " << poruszany_problem << endl;
	cout << "Rekomendacje psychologow: " << rekomendacje_psychologow << endl;
	cout << "Dziedzina: " << dziedzina << endl;
}
void Ksiazka_Psychologiczna::Usun()
{
	delete this;
}