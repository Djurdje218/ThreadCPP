 #include <iostream>
#include <thread>
#include <chrono>
#include <string>

void DoWork(int a, int b, std::string msg)
{
		std:: cout << msg << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\tDoWork\t " << std::endl;

		std::cout << "=====\t" << "DoWork STARTED\t======" << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		std::cout << "a + b = " << a + b << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "=====\t" << "DoWork STOPPED\t======" << std::endl;

	
}

int main()
{
	std::setlocale(LC_ALL, "ru");

	std::thread th(DoWork,2,3,"our message");

	//th.detach(); detach ako ne zelimo da cekamo zavrsetak DoWorka bez greski

	for( size_t i = 0; true; i++ )
	{
		std::cout << " ID potoka =  "<< std::this_thread::get_id() << "\tmain works\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	};
	


	th.join();
	return 0;
}

