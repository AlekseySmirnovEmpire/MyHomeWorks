#include "CommandList.h"
#include <iostream>

int main() {

	int userInput;

	do {
		showCommands();
		std::cin >> userInput;

		switch (userInput)
		{
		case SUM:
			sum();
			break;

		case SAVE:
			save();
			break;

		case LOAD:
			load();
			break;

		case INPUT:
			input();
			break;

		case DISPLAY:
			show();
			break;

		case EXIT:
			break;

		default:
			std::cout << "Wrong input! Try again!" << std::endl;
			break;
		}

		std::cout << "====================================" << std::endl;

	} while (userInput != EXIT);
}