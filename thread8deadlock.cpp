#include <iostream>
#include <mutex>
#include <thread>

#include "SimpleTimer.h"


std::mutex mtx1;
std::mutex mtx2;

void Print(char ch)
{
	mtx1.lock();

	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	
	mtx2.lock();

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
	
	mtx1.unlock();
	mtx2.unlock();
}

void Print2(char ch)
{
	mtx1.lock();

	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	
	mtx2.lock();

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
	
	mtx2.unlock();
	mtx1.unlock();
}


int main()
{
	setlocale(LC_ALL, "ru");

	SimpleTimer timer;

	std::thread t1(Print,'*');
	std::thread t2(Print2,'#');

	t1.join();
	t2.join();

	return 0;
}