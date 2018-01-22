#include "TimeCounter.h"

TimeCounter::TimeCounter()
{
	
}

TimeCounter::~TimeCounter()
{
	
}

void TimeCounter::Start()
{
	begin = clock();
}

double TimeCounter::Measure()
{
	end = clock();
	return end-begin;
}