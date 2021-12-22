#include "classes.h"
#include "clear.h"
#include <iostream>
#include <thread>
#include <map>


int main()
{
	Sportsman sportsman[6];

	std::map<int, std::string> score;

	std::thread t1(startSwim, std::ref(sportsman[0]), std::ref(score));
	std::thread t2(startSwim, std::ref(sportsman[1]), std::ref(score));
	std::thread t3(startSwim, std::ref(sportsman[2]), std::ref(score));
	std::thread t4(startSwim, std::ref(sportsman[3]), std::ref(score));
	std::thread t5(startSwim, std::ref(sportsman[4]), std::ref(score));
	std::thread t6(startSwim, std::ref(sportsman[5]), std::ref(score));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	clear();

	showScore(score);
}
