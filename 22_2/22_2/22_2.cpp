#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isCorrectInput(std::string& input) {
	for (int i = 0; i < input.length(); ++i) {
		if ((input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z')) return false;
	}

	return true;
}

int main() {
	std::map<std::string, int> regList;

	std::string userInput;

	do {
		std::cout << "Input last name in queue or \"next\" to show who's next: ";
		std::getline(std::cin, userInput);

		while (!isCorrectInput(userInput)) {
			std::cout << "Wrong input! Try again: ";
			std::getline(std::cin, userInput);
		}

		if (userInput == "next") {
			std::map<std::string, int>::iterator it = regList.begin();

			if (it == regList.end()) {
				std::cout << "Queue is empty!" << std::endl;
			}
			else {
				std::cout << it->first << " is NEXT!" << std::endl;

				if (it->second > 1) {
					--it->second;
				}
				else {
					regList.erase(it);
				}
			}
		}
		else {
			std::map<std::string, int>::iterator it = regList.find(userInput);

			if (it == regList.end()) regList.emplace(userInput, 1);
			else ++it->second;
		}
	} while (!regList.empty());
}