#include <time.h>

using namespace std;

class TimeCounter
{
	clock_t begin, end;
    double time_spent;
public:
	TimeCounter();
	~TimeCounter();
	void Start();
	double Measure();
};