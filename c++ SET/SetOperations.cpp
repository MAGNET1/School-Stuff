#include "SetOperations.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

extern set<int> numBase;

int _RandomNumber();

SetOperations::SetOperations()
{
	
}
SetOperations::~SetOperations()
{
	
}

int SetOperations::Insert(int * tab, int n, int isRandom)
{
	int i;
	int howMany=0;
	pair<set<int>::iterator,bool> ret;
	
	for(i=0;i<n;i++)
	{
		if(isRandom == RANDOMLY)
			ret = numBase.insert(_RandomNumber());
		else
			ret = numBase.insert(tab[i]);
			
		if(ret.second == true)	howMany++;
	}
	return howMany;
}

int SetOperations::Search(int * tab, int n, int isRandom)
{
	int i;
	int howMany=0;
	set<int>::iterator res;
	
	for(i=0;i<n;i++)
	{
		if(isRandom == RANDOMLY)
			res = numBase.find(_RandomNumber());
		else
			res = numBase.find(tab[i]);
			
		if(res != numBase.end())	howMany++;
	}
	return howMany;
}

int SetOperations::Delete(int * tab, int n, int isRandom)
{
	int i;
	int howMany=0;
	set<int>::iterator res;
	
	for(i=0;i<n;i++)
	{
		if(isRandom == RANDOMLY)
			res = numBase.find(_RandomNumber());
		else
			res = numBase.find(tab[i]);
			
		if(res != numBase.end())
		{
			numBase.erase(res);
			howMany++;
		}
	}
	return howMany;
}