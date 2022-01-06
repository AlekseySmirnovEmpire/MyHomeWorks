#include <iostream>
#include <ctime>
#include "Basket.h"
#include "Market.h"
#include "Support.h"

int main()
{
    std::srand(std::time(nullptr));

    ShoppingBasket shoppingBasket;
    std::cout << "===============WELCOME!===============" << std::endl;

    forever()
    {
        int answer;
        showMenu();

        std::cin >> answer;

        if(static_cast<eCommands>(answer) == EXIT)
        {
            clear();
            break;
        }
        else if (static_cast<eCommands>(answer) > EXIT)
        {
            clear();
            std::cout << "Wrong input! Try again!" << std::endl;
        }
        else
        {
            std::string article;
            int amount;
            std::cout << "Input article and amount: ";
            std::cin >> article >> amount;

            switch (static_cast<eCommands>(answer)) {
                case ADD_IN_CART:
                    shoppingBasket.add(article, amount);
                    break;
                case REMOVE_FROM_CART:
                    shoppingBasket.remove(article, amount);
                    break;
            }
        }
    }

    std::cout << "Press any key to exit" << std::endl;
    wait();
    clear();
    std::cout << "===================GOODBYE!================" << std::endl;
}
