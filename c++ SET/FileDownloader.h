#pragma once
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class FileDownloader
{
	int * tab;
	
public:
	FileDownloader();
	~FileDownloader();
	int * ReadFromFile(string FileName);
	
	int CountLines(string FileName);
	
	void Fill(int * tab, int n);
};