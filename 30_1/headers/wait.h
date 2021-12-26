#pragma once
#include <iostream>

void wait() {

#ifdef _WIN32
	system("pause");

#elif (_LINUX_)
	system("read");

#endif 

}