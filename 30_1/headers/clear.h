#pragma once

void clear() {

#ifdef _WIN32
	system("cls");

#elif (_LINUX_)
	system("clear");

#else
	for (int i = 0; i < 10; ++i)
		std::cout << std::ednl;

#endif 

}