#include "restaurant.h"
#include <iostream>
#include <thread>

int main()
{

	std::thread t1(createOrder);
	std::thread t2(makeOrder);
	std::thread t3(makeDelivery);

	t1.detach();
	t2.detach();
	t3.join();

	std::cout << "================That's all!=================" << std::endl;
}
