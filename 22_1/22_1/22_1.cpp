#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isCorrectNumber(std::string& input) {

	for (int i = 0; i < input.length(); ++i) {
		if ((input[i] < '0' || input[i] > '9') && input[i] != '-') return false;
	}

	return true;
}

bool isLastName(std::string& input) {
	for (int i = 0; i < input.length(); ++i) {
		if ((input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z')) return false;
	}
	return true;
}

int main() {

	std::map<std::string, std::string> phoneBookName;
	std::map<std::string, std::string> phoneBookNumber;

	std::string userInput;

	while (true) {

		std::cout << "Ipnut your data (phone name) or \"-1\" to stop: ";
		std::getline(std::cin, userInput);

		if (userInput.find(' ') != std::string::npos) {
			std::string lastName = userInput.substr(userInput.find(' ') + 1);

			userInput.resize(userInput.find(' '));

			if (isCorrectNumber(userInput) && isLastName(lastName)) {
				if (phoneBookNumber.find(userInput) != phoneBookNumber.end()) {
					std::cout << "This phone number is already occupied! Try again!" << std::endl;

					continue;
				}
				else {
					phoneBookNumber.emplace(userInput, lastName);
				}

				if (phoneBookName.find(lastName) != phoneBookName.end()) {
					std::map<std::string, std::string>::iterator it = phoneBookName.find(lastName);

					it->second += ' ' + userInput;
				}
				else {
					phoneBookName.emplace(lastName, userInput);
				}
			}
			else {
				std::cout << "Wrong input! Try again!" << std::endl;
			}
		}
		else if (userInput == "-1") {
			break;
		}
		else {
			if (isLastName(userInput)) {
				if (phoneBookName.find(userInput) != phoneBookName.end()) {
					std::map<std::string, std::string>::iterator it = phoneBookName.find(userInput);

					std::cout << it->first << ' ' << it->second << std::endl;
				}
				else {
					std::cout << "There is no " << userInput << " in phone book! Try again!" << std::endl;

					continue;
				}
				
			}
			else {
				if (isCorrectNumber(userInput)) {
					if (phoneBookNumber.find(userInput) != phoneBookNumber.end()) {
						std::map<std::string, std::string>::iterator it = phoneBookNumber.find(userInput);

						std::cout << it->first << ' ' << it->second << std::endl;
					}
					else {
						std::cout << "There is no " << userInput << " phone number in book! Try again!" << std::endl;

						continue;
					}
					
				}
				else {
					std::cout << "Wrong input! Try again!" << std::endl;

					continue;
				}
			}
		}
	}
}