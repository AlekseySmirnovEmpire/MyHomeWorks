#pragma once
#include <iostream>

void clear()
{
#ifdef _WIN32
    system("cls");
#elif __linux__ || __unix__
    system("clear");
#elif __APPLE__
    syste("/usr/bin/osascript -e");
#else
    for (int i = 0; i < 10; ++i)
        std::cout << std::endl;
#endif
}
