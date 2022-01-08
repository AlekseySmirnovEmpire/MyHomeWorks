#include <iostream>
#include "Support.h"

void showMenu()
{
    std::cout << ADD << ". Add new key;" << std::endl;
    std::cout << REMOVE << ". Remove key;" << std::endl;
    std::cout << PRINT << ". Print key;" << std::endl;
    std::cout << FIND << ". Find key;" << std::endl;

    std::cout << "Input number of command u wish to do: "; 
}

void clear()
{
    #ifdef _WIN32
        system("cls");
    #elif __linux__ || __unix__
        system("clear");
    #else
        for (int i = 0; i < 10; ++i)
            std::cout << std::endl;
    #endif
}