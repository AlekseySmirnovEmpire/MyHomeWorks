#include <iostream>
#include <string>

int main() {
	std::string appartmentsOwners[10];

	for (int i = 0; i < 10; i++) {
		std::cout << "Input the appartments #" << i + 1 << " owner name: ";
		std::cin >> appartmentsOwners[i];
	}

	int number;

	for (int i = 0; i < 3; i++) {
		std::cout << "Input appartments number: ";
		std::cin >> number;
		if (number < 1 || number > 10) {
			do {
				std::cout << "Wrong input. Please, try again: ";
				std::cin >> number;
			} while (number > 0 && number <= 10);
		}
		std::cout << "Owner of the " << number << " appartments is " << appartmentsOwners[number - 1] << std::endl;
	} 
}