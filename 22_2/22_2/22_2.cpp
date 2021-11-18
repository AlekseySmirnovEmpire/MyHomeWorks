#include <iostream>
#include <map>
#include <string>

bool isCorrectInput(std::string& input) {
	for (int i = 0; i < input.length(); ++i) {
		if ((input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z')) return false;
	}

	return true;
}

int main() {
	std::multimap<char, std::string> regList;

	std::string userInput;

	do {
		std::cout << "Input last name in queue or \"next\" to show who's next: ";
		std::getline(std::cin, userInput);

		while (!isCorrectInput(userInput)) {
			std::cout << "Wrong input! Try again: ";
			std::getline(std::cin, userInput);
		}

		if (userInput == "next") {
			if (regList.empty()) {
				std::cout << "The queue is empty!" << std::endl;
			}
			else {
				std::map<char, std::string>::iterator it = regList.begin();

				std::cout << it->second << " is next!" << std::endl;

				regList.erase(it);
			}
		}
		else {
			regList.emplace(userInput[0], userInput);
		}
	} while (!regList.empty());
}