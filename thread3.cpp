 #include <iostream>
#include <thread>
#include <chrono>
#include <string>

void DoWork(int &a)
{
		
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "DoWork STARTED\t======" << std::endl;

	
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

		a = a * 2;

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "DoWork STOPPED\t======" << std::endl;

	
}

int main()
{
	std::setlocale(LC_ALL, "ru");

	int q = 5;

	std::thread t(DoWork, std::ref(q));

	//th.detach(); detach ako ne zelimo da cekamo zavrsetak DoWorka bez greski

	 for( size_t i = 0; i < 10; i++ )
	{
		std::cout << " ID potoka =  "<< std::this_thread::get_id() << "\tmain works\t" << i << std::endl;
	 	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	 };
	

	t.join();
	std::cout << q << std::endl;

	return 0;
}

