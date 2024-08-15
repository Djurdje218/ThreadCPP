#include <iostream>
#include <mutex>
#include <thread>

#include "SimpleTimer.h"


std::mutex mtx;

void Print(char ch)
{
	std::unique_lock<std::mutex> ul(mtx,std::defer_lock);

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	ul.lock();

	for( int i = 0; i < 5; i++)
	{
		for( int i = 0; i < 10; i++)
		{
			std::cout << ch;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	ul.unlock();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

}

int main()
{
	setlocale(LC_ALL, "ru");

	SimpleTimer timer;

	std::thread t1(Print, '*');
	std::thread t2(Print, '#');

	t1.join();
	t2.join();

	//git branch change

	return 0;
}