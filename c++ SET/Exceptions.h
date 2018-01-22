#pragma once
#include <string>
#include <iostream>

using namespace std;

class ErrorHandler
{
private:
	string m_error;
 
public:
	ErrorHandler(string error)
	{
		m_error = error;
	}
 
	 const char* getError() { return m_error.c_str(); }
};