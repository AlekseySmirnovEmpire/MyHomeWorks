#include <iostream>
#include <fstream>
#include <string>

bool isDateCorrect(std::string date) {
	int day = std::stoi(date.substr(0, 2));
	int month = std::stoi(date.substr(3, 2));
	int year = std::stoi(date.substr(6, 4));

	if ((year > 1900 && year < 2021) && (month > 0 && month <= 12)) {
		if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				&& day <= 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) || 
				(month == 2 && ((year % 4 == 0 && day <= 29) || (year % 4 != 0 && day <= 28))) && day > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	std::ofstream file("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_1\\statements.txt", std::ios::app);

	if (!file.is_open()) {
		std::cout << "Error! File not found!" << std::endl;
	}
	else {
		std::string data;
		int sum;
		char answer = 'y';

		while (answer != 'n') {
			std::cout << "Input first name: ";
			std::getline(std::cin, data);
			file << data << ' ';

			std::cout << "Input last name: ";
			std::getline(std::cin, data);
			file << data << ' ';

			std::cout << "Input date in format dd.mm.yyyy: ";
			std::getline(std::cin, data);

			while (!isDateCorrect(data)) {
				std::cout << "Wrong input, try again: ";
				std::getline(std::cin, data);
			}

			file << data << ' ';

			std::cout << "Input sum amount of payments in RUB: ";
			std::cin >> sum;
			std::cin.ignore();

			while (sum < 1) {
				std::cout << "Wrong! input correct amount: ";
				std::cin >> sum;
				std::cin.ignore();
			}

			file << sum << std::endl;

			std::cout << "~~~~~~~~~~~~~Data saved!~~~~~~~~~~~~~~~" << std::endl;
			std::cout << "Do you want to continue (y/n)? ";
			std::cin >> answer;
			std::cin.ignore();
		}

		file.close();
		std::cout << "-----------FILE CLOSE--------------" << std::endl;
	}
}