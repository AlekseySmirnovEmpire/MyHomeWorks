#include "header.h"
#include <iostream>

void showMenu() {

	std::cout << "Number of command you wish to do:" << std::endl;

	std::cout << GET << ". to get response;" << std::endl;
	std::cout << POST << ". to get response;" << std::endl;
	std::cout << PUT << ". to get response;" << std::endl;
	std::cout << eDELETE << ". to get response;" << std::endl;
	std::cout << PATCH << ". to get response;" << std::endl;
	std::cout << EXIT << ". to get response;" << std::endl;

	std::cout << "Input here: ";
}