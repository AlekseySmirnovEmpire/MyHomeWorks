#include "support.h"
#include <iostream>

void clear() {

#ifdef _WIN32
	system("cls");

#elif (_LINUX_)
	system("clear");

#else
	for (int i = 0; i < 10; ++i)
		std::cout << std::endl;

#endif 
}

void wait() {

#ifdef _WIN32
	system("pause");

#elif (_LINUX_)
	system("read");

#endif
}