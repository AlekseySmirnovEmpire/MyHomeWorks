#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>


struct BirthDays
{
	std::string name = "";
	std::string date = "";
};

bool isCorrectName(std::string& input) {
	for (int i = 0; i < input.length(); ++i) {
		if (!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z') && input[i] != ' ') return false;
	}

	return true;
}

bool isCorrectDate(std::string& date) {

	if (date.length() != 10) return false;

	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if ((year > 1900 && year < 2021) && (month > 0 && month <= 12)) {
		if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			&& day <= 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) ||
			(month == 2 && ((year % 4 == 0 && day <= 29) || (year % 4 != 0 && day <= 28))) || day > 0) {
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

void inputDataInList(std::string& name, std::string& date, std::vector<BirthDays>& origin) {

	BirthDays* temp = new BirthDays;

	temp->name = name;
	temp->date = date;

	origin.push_back(*temp);

	delete temp;

	temp = nullptr;
}

int getDaysCount(std::string& date) {

	int* month = new int;

	*month = std::stoi(date.substr(5, 2)) - 1;

	int output = std::stoi(date.substr(8, 2));

	switch (*month)
	{

	case 12:
		output += 31;
		--* month;

	case 11:
		output += 30;
		--* month;

	case 10:
		output += 31;
		--* month;

	case 9:
		output += 30;
		--* month;

	case 8:
		output += 31;
		--* month;

	case 7:
		output += 31;
		--* month;

	case 6:
		output += 30;
		--* month;

	case 5:
		output += 31;
		--* month;

	case 4:
		output += 30;
		--* month;

	case 3:
		output += 31;
		--* month;

	case 2:
		if (std::stoi(date.substr(0, 4)) % 4 == 0) output += 29;
		else output += 28;
		--* month;

	case 1:
		output += 31;
		--* month;

	default:
		break;
	}

	delete month;
	month = nullptr;

	return output;
}

int getDaysCount(std::tm* date) {

	int* month = new int;

	*month = date->tm_mon - 1;

	int output = date->tm_mday;

	switch (*month)
	{

	case 12:
		output += 31;
		--* month;

	case 11:
		output += 30;
		--* month;

	case 10:
		output += 31;
		--* month;

	case 9:
		output += 30;
		--* month;

	case 8:
		output += 31;
		--* month;

	case 7:
		output += 31;
		--* month;

	case 6:
		output += 30;
		--* month;

	case 5:
		output += 31;
		--* month;

	case 4:
		output += 30;
		--* month;

	case 3:
		output += 31;
		--* month;

	case 2:
		if (date->tm_year % 4 == 0) output += 29;
		else output += 28;
		--* month;

	case 1:
		output += 31;
		--* month;

	default:
		break;
	}

	delete month;
	month = nullptr;

	return output;
}

int main() {

	std::string userInput;

	std::vector<BirthDays> birthdaysFriends;

	while (true) {

		std::string date;

		std::cout << "Input your friend name: ";
		std::getline(std::cin, userInput);

		while (!isCorrectName(userInput)) {
			std::cout << "Wrong input! Try again: ";
			std::getline(std::cin, userInput);
		}

		if (userInput == "end") break;

		std::cout << "Input his birthday (YYYY/MM/DD): ";
		std::getline(std::cin, date);

		while (!isCorrectDate(date)) {
			std::cout << "Wrong input! Try again: ";
			std::getline(std::cin, date);
		}

		inputDataInList(userInput, date, birthdaysFriends);

	}

	std::cout << "=========================================" << std::endl;

	std::vector<int> tempIndexes = { 0 };

	std::time_t t = std::time(nullptr);
	std::tm* local = std::localtime(&t);

	int* temp = new int;
	*temp = std::abs(getDaysCount(birthdaysFriends[0].date) - getDaysCount(local));

	for (int i = 1; i < birthdaysFriends.size(); ++i) {

		if (std::abs(getDaysCount(birthdaysFriends[i].date) - getDaysCount(local)) < *temp) {

			if (tempIndexes.size() > 1) {

				tempIndexes.resize(1);
			}

			tempIndexes[0] = i;

			*temp = std::abs(getDaysCount(birthdaysFriends[i].date) - getDaysCount(local));
		}
		else if (std::abs(getDaysCount(birthdaysFriends[i].date) - getDaysCount(local)) == *temp) {

			tempIndexes.push_back(i);
		}
	}

	delete temp;
	temp = nullptr;

	if (tempIndexes.size() > 1) std::cout << "You've got more than one friend's birthdays in one day in nearest time!" << std::endl;

	std::cout << "Nearest birthdays: " << std::endl;

	for (int i = 0; i < tempIndexes.size(); ++i) {

		std::cout << birthdaysFriends[tempIndexes[i]].name << " - " << birthdaysFriends[tempIndexes[i]].date << std::endl;
	}

	std::cout << "===============THAT'S ALL FOLKS!====================" << std::endl;
}