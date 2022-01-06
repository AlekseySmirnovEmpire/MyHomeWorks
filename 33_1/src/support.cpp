#include <iostream>
#include "Support.h"

void clear()
{
#ifdef _WIN32
    system("cls");
#elif __linux__ || __unix__
    system("clear");
#else
    for(int i = 0; i < 10; ++i)
        std::cout << std::endl;
#endif
}

void wait()
{
#ifdef _WIN32
    system("pause");
#elif __linux__ || __unix__
    system("read");
#endif
}

void showMenu()
{
    std::cout << ADD_IN_CART << ". To add product in cart;" << std::endl;
    std::cout << REMOVE_FROM_CART << ". To remove from cart;" << std::endl;
    std::cout << EXIT << ". To exit." << std::endl;
    std::cout << "Type number of command: " << std::endl;
}
