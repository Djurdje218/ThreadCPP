#include <iostream>
#include <mutex>
#include <thread>

#include "SimpleTimer.h"


std::mutex mtx;

void Print(char ch)
{
	mtx.lock();

	for( int i = 0; i < 5; i++)
	{
		for( int i = 0; i < 10; i++)
		{
			std::cout << ch;
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	mtx.unlock();
}

int main()
{
	setlocale(LC_ALL, "ru");

	SimpleTimer timer;

	std::thread t1(Print, '*');
	std::thread t2(Print, '#');

	t1.join();
	t2.join();

	return 0;
}