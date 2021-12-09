#include "Commands.h"
#include <iostream>


int main() {

	int userInput = 0;

	showCommandList();
	std::cin >> userInput;

	while (userInput != SCALPEL) {
		std::cout << "First of all you need to make scalpel cut! Try again: ";
		std::cin >> userInput;
	}

	Point startPoint[2];

	scalpelMake(startPoint, true);

	bool isOver = false;

	std::cout << "=============START=============" << std::endl;

	do {

		showCommandList();
		std::cin >> userInput;

		switch (userInput)
		{

		case SCALPEL:

			scalpelMake(startPoint);

			break;

		case HEMOSTAT:

			hemostatMake();

			break;

		case TWEEZERS:

			tweezersMake();

			break;

		case SUTURE:

			sutureMake(startPoint, &isOver);

			break;

		default:
			std::cout << "Wrong input! Try again!" << std::endl;

			break;
		}

		std::cout << "=========================" << std::endl;

	} while (!isOver);

	std::cout << "Operation is over!" << std::endl;

}