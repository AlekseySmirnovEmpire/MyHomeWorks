#include <iostream>
#include "Film.h"
#include "nlohmann/json.hpp"

Film::Film(const nlohmann::json& dict)
{
    name = dict["Title"];
    country = dict["Country"];
    date = dict["Date"];
    filmStudio = dict["Film studio"];
    scriptwriter = dict["Script writer"];
    producer = dict["Producer"];

    actors = dict["Actors"];
}

void Film::showInfo()
{
    std::cout << "Title: " << name << std::endl;
    std::cout << "Country: " << country << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Film studio: " << filmStudio << std::endl;
    std::cout << "Script writer: " << scriptwriter << std::endl;
    std::cout << "Producer: " << producer << std::endl;

    std::cout << "Roles:" << std::endl;

    for(const auto& elem : actors)
        std::cout << elem.first << elem.second << std::endl;
}