#include <iostream>
#include "Reestr.h"
#include "Support.h"

int main(int, char**) 
{
    forever()
    {
        showMenu();

        int answer;
        std::cin >> answer;

        switch(answer)
        {
        case ADD:
            clear();
            break;
        }
    }
}