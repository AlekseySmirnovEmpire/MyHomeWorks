#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

struct Statesment
{
	std::string firstName = "unknown";
	std::string lastName = "unknown";
	std::string date = "01.01.1900";
	int payment = 0;
};

bool isCorrectDate(std::string date) {
	int day = std::stoi(date.substr(0, 2));
	int month = std::stoi(date.substr(3, 2));
	int year = std::stoi(date.substr(6, 4));

	if ((year >= 1900 && year <= 2021) && (month > 0 && month <= 12)) {
		if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				&& day <= 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) ||
				(month == 2 && ((year % 4 == 0 && day <= 29) || (year % 4 != 0 && day <= 28))) && day > 0) {
			return true;
		}
		else return false;
	}
	else return false;
}

void showHelpMenu(std::string input) {
	std::cout << "\"/list\" - show statesment's lists;" << std::endl;
	std::cout << "\"/add\" - add new data in statesment's lists;" << std::endl;
	std::cout << "\"/exit\" - close programme;" << std::endl;
}

bool isCorrectInput(std::string input) {
	return (input == "/add" || input == "/help" || input == "/exit" || input == "/list");
}

void newLineAdd(std::ofstream& file, Statesment& person) {
	std::cout << "Input name first name: ";
	std::getline(std::cin, person.firstName);

	std::cout << "Input name last name: ";
	std::getline(std::cin, person.lastName);

	std::cout << "Input date (dd.mm.yyyy): ";
	std::getline(std::cin, person.date);
	while (!isCorrectDate(person.date)) {
		std::cout << "Wrong input, try again: ";
		std::getline(std::cin, person.date);
	}

	std::cout << "Input peayment amount: ";
	std::cin >> person.payment;
	std::cin.ignore();

	file << person.firstName << ' ' << person.lastName << ' ' << person.date << ' ' << person.payment << std::endl;
}

int main() {
	std::cout << "~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~~" << std::endl;

	Statesment person;

	
	std::string userInput = "";

	while (userInput != "/exit") {
		std::cout << "Write command (\"/help\" to show commands): ";
		std::getline(std::cin, userInput);
		while (!isCorrectInput(userInput)) {
			std::cout << "Wrong command, try again: ";
			std::getline(std::cin, userInput);
		}

		while (userInput == "/help") {
			showHelpMenu(userInput);
			std::cout << "Write command: ";
			std::getline(std::cin, userInput);
		}

		if (userInput == "/list") {

			std::ifstream file("statements.txt");

			if (!file.is_open()) {
				std::cout << "Error! File not found!" << std::endl;
			}
			else {
				while (!file.eof()) {
					file >> person.firstName >> person.lastName >> person.date >> person.payment;
					std::cout << person.firstName << ' ' << person.lastName << ' ' << person.date << ' ' << person.payment << std::endl;
				}

				file.close();
			}			
		}
		else if (userInput == "/add") {
			std::ofstream file("statements.txt", std::ios::app);

			if (file.is_open()) {
				newLineAdd(file, person);
				file.close();
			}
			else {
				std::cout << "Error! File not found!" << std::endl;
			}
			
		}
	}
}