#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>

#include "SetDefinition.h"
#include "Exceptions.h"
#include "FileDownloader.h"
#include "SetOperations.h"
#include "TimeCounter.h"

#define RANDOMLY 0
#define FROM_FILE 1

int _RandomNumber()
{
	return (rand()%25000) * (rand()%400);
}

using namespace std;

int main()
{
	srand(2);
	int N[] = {100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000};
	FileDownloader numberBase; // rand.txt service
	SetOperations hexKey; // Set operations (insert, search etc.)
	TimeCounter counter; // time measurement
	
	// retrieves how many numbers and numbers themselves
	//int randAmount = numberBase.CountLines("rand.txt");
	int * randTab;
	try
	{
		randTab = numberBase.ReadFromFile("rand.txt");
	}
	catch(ErrorHandler &e)
	{
		cout << e.getError() << endl;
		return 0;
	}
	
	//perform
	unsigned int i;
	int resultCount;
	double resTime;
	cout << endl;
	for(i=0;i<9;i++)
	{
		counter.Start();
		resultCount = hexKey.Insert(randTab, N[i], FROM_FILE);
		resTime = counter.Measure();
		cout << "Wstawianie dla " << N[i] << " elementow z pliku: " << resTime << "ms [" << resultCount << "]" << endl;
		
		counter.Start();
		resultCount = hexKey.Search(randTab, N[i], FROM_FILE);
		resTime = counter.Measure();
		cout << "Wyszukiwanie dla " << N[i] << " elementow z pliku: " << resTime << "ms [" << resultCount << "]" << endl;
		
		counter.Start();
		resultCount = hexKey.Search(randTab, N[i], RANDOMLY);
		resTime = counter.Measure();
		cout << "Wyszukiwanie dla " << N[i] << " elementow losowo: " << resTime << "ms [" << resultCount << "]" << endl;
		
		counter.Start();
		resultCount = hexKey.Delete(randTab, N[i], RANDOMLY);
		resTime = counter.Measure();
		cout << "Usuwanie dla " << N[i] << " elementow losowo: " << resTime << "ms [" << resultCount << "]" << endl;
		
		counter.Start();
		resultCount = hexKey.Delete(randTab, N[i]/2, FROM_FILE);
		resTime = counter.Measure();
		cout << "Usuwanie dla " << N[i] << " elementow losowo: " << resTime << "ms [" << resultCount << "]" << endl << endl;
	}
	/*for (set<int>::iterator it=numBase.begin(); it!=numBase.end(); ++it)
	    cout << ' ' << *it;
	cout<<"\n";*/
	
	return 0;
}