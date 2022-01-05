#pragma once
#include <iostream>

void wait()
{
#ifdef _WIN32
    system("pause");
#elif __linux__ || __unix__
    system("read");
#endif
}