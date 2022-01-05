#include "Film.h"
#include "Menu.h"
#include <iostream>

void showMenu()
{
    std::cout << "We've got films: " << std::endl;
    std::cout << SHAWSHANK_REDEMPTION << ". Shawshank redemption;" << std::endl;
    std::cout << LORD_OF_THE_RING << ". Lord of the ring;" << std::endl;
    std::cout << STAR_WARS << ". Star wars;" << std::endl;
    std::cout << STAR_TREK << ". Star trek;" << std::endl;
    std::cout << BREAKING_BAD << ". Breaking bad." << std::endl;

    std::cout << "Input number of film you wish to watch: ";
}