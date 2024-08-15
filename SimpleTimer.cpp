#include "SimpleTimer.h"

SimpleTimer::SimpleTimer()
{
	start = std::chrono::steady_clock::now();
}

SimpleTimer::~SimpleTimer()
{
	end = std::chrono::steady_clock::now();
	duration = end - start;
	float result = duration.count();

	std::cout << "proslo vremeni " << result <<" sekund" << std::endl;
}
