#pragma once
#include <set>

#define RANDOMLY 0
#define FROM_FILE 1

class SetOperations
{
	
public:
	SetOperations();
	~SetOperations();
	
	int Insert(int * tab, int n, int isRandom);
	int Search(int * tab, int n, int isRandom);
	int Delete(int * tab, int n, int isRandom);
};