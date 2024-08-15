 #include <iostream>
#include <thread>
#include <chrono>
#include <string>

int Sum(int a, int b)
{
		
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "Sum STARTED\t======" << std::endl;

	
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	
		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "Sum STOPPED\t======" << std::endl;

		return a + b;
}

int main()
{
	std::setlocale(LC_ALL, "ru");

	int result;

	//std::thread t(Sum, 2, 5); pogresno

	auto f = [&result]() {	result = Sum(2, 5);	};
	
	std::thread t(f);
	
	 for( size_t i = 0; i < 10; i++ )
	{
		std::cout << " ID potoka =  "<< std::this_thread::get_id() << "\tmain works\t" << i << std::endl;
	 	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	 };
	


	t.join();
	std::cout << " Rezultat je " << result << std::endl;
	return 0;
}

