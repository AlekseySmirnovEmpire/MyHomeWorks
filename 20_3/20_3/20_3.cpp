#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

void createRiver() {
	std::srand(std::time(nullptr));
	std::ofstream river("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_3\\river.txt");

	std::string types[] = { "sunfish", "shad", "carp", "bass", "bullhead", "walleye", "catfish" };

	for (int i = 0; i < 10; i++) {
		river << types[rand() % (sizeof(types) / sizeof(std::string))] << std::endl;
	}

	river.close();
}

int main() {
	createRiver();

	int fishCounter = 0;
	char answer = 'y';

	std::ifstream inRiver("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_3\\river.txt");

	if (!inRiver.is_open()) {
		std::cout << "Error! File not found!" << std::endl;
	}
	else {
		std::cout << "~~~~~~~~~~~~~~Let's start fishing!~~~~~~~~~~~~~~~" << std::endl;

		while (answer == 'y') {
			std::string userInput;
			std::cout << "Input type of fish you wish to catch: ";
			std::getline(std::cin, userInput);

			bool isFound = false;
			std::string temp;
			while (!inRiver.eof()) {
				inRiver >> temp;
				if (temp == userInput) {
					isFound = true;
					break;
				}
			}
			if (isFound) {
				std::cout << "CATCH!" << std::endl;

				std::ofstream basket("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_3\\basket.txt", std::ios::app);

				basket << userInput << std::endl;
				fishCounter++;

				basket.close();
				std::cout << "------" << userInput << " have been added to the basket!-------" << std::endl;
			}
			else {
				std::cout << "Sorry, you haven't caught anything!" << std::endl;
			}

			std::cout << "Do you want to continue (y/n)? ";
			std::cin >> answer;
			std::cin.ignore();
		}

		inRiver.close();

		std::cout << "-------------------Fishing is over---------------------" << std::endl;
		std::cout << "Total fish caught in this session: " << fishCounter << std::endl;
	}
}