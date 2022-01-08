#include <iostream>
#include "Reestr.h"
#include "Support.h"

int main(int, char**) 
{
    bool isOver = false;
    forever()
    {
        showMenu();

        Reestr<int, int> red;

        int answer;
        std::cin >> answer;

        answer = static_cast<eCommands>(answer);

        int key, data;

        if(answer == EXIT)
            break;
        else
        {
            std::cout << "Input key: ";
            int key;
            std::cin >> key;

            if(answer == ADD)
            {
                std::cout << "Input data: ";
                std::cin >> data;

                red.addKey(key, data);
            }
            else if (answer == PRINT)
                red.printKey(key);
            else if (answer == REMOVE)
                red.removeKey(key);
            else
                red.findKey(key);
        }
    }
}