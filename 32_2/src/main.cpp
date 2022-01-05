#include <iostream>
#include <fstream>
#include <string>
#include "Film.h"
#include "Menu.h"
#include "Wait.h"
#include "nlohmann/json.hpp"

int main()
{
    std::cout << "================WELCOME!================" << std::endl;

    int answer;
    showMenu();
    std::cin >> answer;

    std::string name = "record" + std::to_string(answer) + ".json";

    std::ifstream file(name);

    if (file.is_open())
    {
        nlohmann::json dict;

        file >> dict;

        Film film(dict);

        film.showInfo();

        file.close();
    }
    else
    {
        std::cout << "FILE NOT FOUND!";
        return 1;
    }

    std::cout << "Press any key to exit" << std::endl;

    wait();

    std::cout << "================GOODBYE!================" << std::endl;
}