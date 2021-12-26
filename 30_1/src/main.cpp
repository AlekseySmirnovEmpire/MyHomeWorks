#include "clear.h"
#include "header.h"
#include <iostream>


int main()
{
	int userInput;

	do {

		showMenu();
		std::cin >> userInput;

		doRequest(userInput);

	} while (userInput != EXIT);

	clear();

	std::cout << "==============THE END!================" << std::endl;
}
