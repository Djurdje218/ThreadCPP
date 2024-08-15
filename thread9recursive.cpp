#include <iostream>
#include <mutex>
#include <thread>
std::recursive_mutex rm;
void Foo(int a)
{
	rm.lock();

	std::cout << a << " ";
	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	if( a < 2)
	{
		std::cout << std::endl;
		rm.unlock();
		return;
	}

	a--;
	Foo(a);

	rm.unlock();
}





int main()
{
	setlocale(LC_ALL, "ru");

	std::thread t1(Foo,10);
	std::thread t2(Foo,10);

	t1.join();
	t2.join();

	return 0;
}