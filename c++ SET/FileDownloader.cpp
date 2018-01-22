#include "FileDownloader.h"
#include "Exceptions.h"

extern set<int> numBase;

FileDownloader::FileDownloader()
{
	
}

FileDownloader::~FileDownloader()
{
	
}

int * FileDownloader::ReadFromFile(string FileName)
{
	int * base;
	int n;
	string line;
	//delete[] base;
	
	// retrieving number of lines from rand.txt
	n = FileDownloader::CountLines(FileName);
	
	base = new int[n];
	
	ifstream p("rand.txt");
	
	if(p.is_open())
	{
		int i=0;
		while(getline(p, line))	base[i++] = atoi(line.c_str());
		p.close();
	}
	else throw ErrorHandler("Could not open the file!"); 
	
	return base;
}

int FileDownloader::CountLines(string FileName)
{
	ifstream p(FileName.c_str());
	int i=0;
	if(p.is_open())
	{
		string line;
		while(getline(p, line))	i++;
	}
	else throw ErrorHandler("Could not open the file!");
	
	return i;
}

void FileDownloader::Fill(int * tab, int n)
{
	int i;
	for(i=0;i<n;i++)	numBase.insert(tab[i]);
}