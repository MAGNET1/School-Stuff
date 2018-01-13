#include <iostream>
#include <vector>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class InputException
{
private:
	string m_error;
 
public:
	InputException(string error)
	{
		m_error = error;
	}
 
	 const char* getError() { return m_error.c_str(); }
};

class NegativeNumber
{
private:
	string m_error;
 
public:
	NegativeNumber(string error)
		: m_error(error)
	{
	}
 
	 const char* getError() { return m_error.c_str(); }
};

class IncorrectNumber
{
private:
	string m_error;
 
public:
	IncorrectNumber(string error)
		: m_error(error)
	{
	}
 
	 const char* getError() { return m_error.c_str(); }
};

class NoBooks
{
private:
	string m_error;
 
public:
	NoBooks(string error)
		: m_error(error)
	{
	}
 
	 const char* getError() { return m_error.c_str(); }
};

class NoMoney
{
private:
	string m_error;
 
public:
	NoMoney(string error)
		: m_error(error)
	{
	}
 
	 const char* getError() { return m_error.c_str(); }
};

class FileError
{
private:
	string m_error;
 
public:
	FileError(string error)
		: m_error(error)
	{
	}
 
	 const char* getError() { return m_error.c_str(); }
};