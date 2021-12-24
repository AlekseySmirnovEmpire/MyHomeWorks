#include "trains.h"
#include <iostream>
#include <string>
#include <vector>

Train::Train() {

	std::string name;
	std::cout << "Enter name: ";
	std::getline(std::cin, this->name);

	std::cout << "Enter time to arrive: ";
	std::cin >> this->speed;
	std::cin.ignore();
}

void createTrain(std::vector<Train>& trains) {

	const int trainsCount = 3;

	for (int i = 0; i < trainsCount; ++i) {

		std::cout << "=======Train # " << i + 1 << "======" << std::endl;

		trains.push_back(Train());
	}
}