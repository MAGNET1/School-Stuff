#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>

#define TAB_SIZE 997
#define ADR_LINIOWE 0
#define ADR_MIESZANIE 1

#define KOMUNIKATY 1

int * Inicjalizuj(int * tab)
{
	tab = (int*) malloc(sizeof(int)*TAB_SIZE);
	int i;
	for(i=0;i<TAB_SIZE;i++)
	{
		tab[i] = 0;
	}
	return tab;
}

int FunkcjaMieszajaca(int k)
{
	return ((k%1000)+(int)pow(2, k%10)+1) % 997;
}

int MieszaniePodwojne(int k)
{
	return ((3*k)%19) + 1;
}

//sprawdza, co widnieje w tablicy o podanym indexie
// 1 - element istnieje juz w liscie
// 0 - w tablicy o podanym indexie nie ma zadnego elementu
// -1 - pod danym indexem znajduje sie juz element o innej wartosci
int CzyJest(int * tab, int k, int x)
{
	if(tab[x] == k)	return 1;
	if(tab[x] == 0)	return 0;
	return -1;
}
//DLA DODAWANIA:
// Funkcja zwraca index pola w tablicy, wykorzystujac liniowke lub mieszanie podwojne
// -1 - w tablicy istnieje juz pole o takiej wartosci
// i - index pustego pola, w ktorym mozna umiescic element
// 0 - brak miejsca w tablicy

int ZnajdzIndexLiniowe(int * tab, int k, int x, int mode)
{
	int i = x+1;
	int A=0;
	while(i<TAB_SIZE)
	{
		A = CzyJest(tab, k, i);
		if(A == -1)
		{
			if(mode == ADR_LINIOWE)	i++;
			else i = (i + MieszaniePodwojne(i))%TAB_SIZE;
			continue;
		}
		if(A == 0)	return i;
		if(A == 1)	return -1;
	}
	return 0;
}

int WstawElement(int * tab, int k, int mode)
{
	
	int x = FunkcjaMieszajaca(k);
	if(KOMUNIKATY)	printf("\nProba wstawienia to tablicy elementu o numerze %d (przewiduje pod %d)... ", k, x);
	
	int A = CzyJest(tab, k, x);
	
	switch(A)
	{
		case 1:
		{
			if(KOMUNIKATY)	printf("jest juz taka liczba!");
			return 0;
		}
		case 0:
		{
			if(KOMUNIKATY)	printf("umieszczono! (%d)", x);
			tab[x] = k;
			return 1;
		}
		case -1:
		{
			//wykorzystanie adresowania liniowego
			int gdzie = ZnajdzIndexLiniowe(tab, k, x, mode);
			if(gdzie == 0)
			{
				if(KOMUNIKATY)	printf("brak miejsca w tablicy!");
				return 0;
			}
			if(gdzie == -1)
				{
				if(KOMUNIKATY)	printf("jest juz taka liczba!");
				return 0;
			}
			tab[gdzie] = k;
			if(KOMUNIKATY)	printf("umieszczono! (%d)", gdzie);
			return 1;
			}
	}
	return 0;
}

int UsunElement(int * tab, int k)
{
	if(KOMUNIKATY)	printf("\nProba usuniecia z tablicy elementu o kluczu %d... ", k);
	int i;
	for(i=0;i<TAB_SIZE;i++)
	{
		if(tab[i] == k)
		{
			if(KOMUNIKATY)	printf("usunieto! (%d)", i);
			tab[i] = -1;
			return 1;
		}
	}
	if(KOMUNIKATY)	printf("brak elementu w tablicy!");
	return 0;
}

void WstawXElementow(int * tab, int x, int mode)
{
	int randd;
	int i;
	for(i=0;i<x;i++)
	{
		while(1)
		{
			randd = rand()%20000 + 20000;
			if(WstawElement(tab, randd, mode))	break;
			
		}
	}
}

int WyszukajElement(int * tab, int k)
{
	if(KOMUNIKATY)	printf("\nProba wyszukania elementu o kluczu %d... ", k);
	int i;
	for(i=0;i<TAB_SIZE;i++)
	{
		if(tab[i] == k)
		{
			if(KOMUNIKATY)	printf("znaleziono! (%d)", i);
			return i;
		}
	}
	if(KOMUNIKATY)	printf("brak elementu w tablicy!");
	return 0;
}

void Wyswietl(int * tab, int a, int b)
{
	if(KOMUNIKATY)	printf("\nWyswietlanie zawartosc tablicy (%d-%d)", a, b);
	for(;a<b+1;a++)
	{
		if(KOMUNIKATY)	printf("%d ", tab[a]);
	}
}

int main()
{	
    srand(time(NULL));
	
	FILE *p = fopen("inlab06.txt", "r");
    int x, k1, k2, k3, k4;
    fscanf(p, "%d %d %d %d %d", &x, &k1, &k2, &k3, &k4);
    fclose(p);
	
	int * tab = NULL;
	
    clock_t begin, end;
    double time_spent, time_spent2;
	//LINIOWE
    begin = clock();
	tab = Inicjalizuj(tab);
	UsunElement(tab, k1);
	WstawElement(tab, k1, ADR_LINIOWE);
	Wyswietl(tab, 0, 100);
	WstawXElementow(tab, x, ADR_LINIOWE);
	Wyswietl(tab, 0, 100);
	WstawElement(tab, k2, ADR_LINIOWE);
	WstawElement(tab, k3, ADR_LINIOWE);
	WstawElement(tab, k4, ADR_LINIOWE);
	Wyswietl(tab, 0, 100);
	Wyswietl(tab, 500, 600);
	UsunElement(tab, k3);
	UsunElement(tab, k4);
	Wyswietl(tab, 0, 100);
	Wyswietl(tab, 500, 600);
	end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nCzas obslugi dla liniowego: %f\n",time_spent);

	//MIESZANIE
	begin = clock();
	tab = Inicjalizuj(tab);
	UsunElement(tab, k1);
	WstawElement(tab, k1, ADR_MIESZANIE);
	Wyswietl(tab, 0, 100);
	WstawXElementow(tab, x, ADR_MIESZANIE);
	Wyswietl(tab, 0, 100);
	WstawElement(tab, k2, ADR_MIESZANIE);
	WstawElement(tab, k3, ADR_MIESZANIE);
	WstawElement(tab, k4, ADR_MIESZANIE);
	Wyswietl(tab, 0, 100);
	Wyswietl(tab, 500, 600);
	UsunElement(tab, k3);
	UsunElement(tab, k4);
	Wyswietl(tab, 0, 100);
	Wyswietl(tab, 500, 600);
	end = clock();
	time_spent2 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nCzas obslugi dla mieszania podwojnego: %f\n",time_spent2);
	
	printf("\n********************************");
	printf("\nWYNIKI:                        *");
	printf("\nLiniowo: %f              *", time_spent);
	printf("\nMieszanie podwojne: %f   *", time_spent2);
	printf("\n********************************\n\n");

}