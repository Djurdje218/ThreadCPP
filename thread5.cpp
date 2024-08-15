 #include <iostream>
#include <thread>




class MyClass
{
public: 
	void DoWork()
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "DoWork STARTED\t======" << std::endl;

	
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	
		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "DoWork STOPPED\t======" << std::endl;
	}

	void DoWork2(int a)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "DoWork2 STARTED\t======" << std::endl;

	
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

		std::cout << "DoWork2 значение параметра\t " << a << std::endl;

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "DoWork2 STOPPED\t======" << std::endl;		
	}

	int Sum( int a, int b)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "Sum STARTED\t======" << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

		std::cout << "ID = potoka = " << std::this_thread::get_id() << "\t=====\t" << "Sum STOPPED\t======" << std::endl;

		return a + b; 
	}
		
};

int main()
{
	std::setlocale(LC_ALL, "ru");

	int result;
	MyClass m;
	

	std::thread t([&]()
	{
		result = m.Sum(2, 5);
	});

	std::thread t1(&MyClass::DoWork, m); 	
	std::thread t2(&MyClass::DoWork2, m, 5); 	// moze i preko lambde std::thread t2([&](){m.DoWork2(5);});
	std::thread t3([&m](){m.DoWork2(5);}); 
	 for( size_t i = 0; i < 10; i++ )
	{
		std::cout << " ID potoka =  "<< std::this_thread::get_id() << "\tmain works\t" << i << std::endl;
	 	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	 };
	
	 t.join();
	 t1.join();
	 t2.join();
	 t3.join();
	 std::cout << "RESULT\t" << result << std::endl;
	
	return 0;
}

