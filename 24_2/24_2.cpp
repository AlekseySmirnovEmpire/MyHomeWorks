#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>

enum eMonth
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

struct BirthDays
{
	std::string name = "";
	std::tm date;
};

int convertToDay(std::tm& tm) {

	int tempMonth = tm.tm_mon - 1;

	int output = 0;

	while (tempMonth != 0) {
		if (tempMonth == 1 || tempMonth == 3 || tempMonth == 5 || tempMonth == 7 
				|| tempMonth == 8 || tempMonth == 10 || tempMonth == 12) {
			output += 31;
		}
		else if (tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11) {
			output += 30;
		}
		else if (tm.tm_year % 4 == 0 && tempMonth == 2) {
			output += 29;
		}
		else {
			output += 28;
		}

		--tempMonth;
	}

	return output;
}

void searchNearestBirthDay(std::vector<BirthDays>& input, std::vector<BirthDays>& output) {

	std::time_t start = std::time(nullptr);
	std::tm nowTime = *std::localtime(&start);

	int temp = convertToDay(nowTime);

	for (int i = 0; i < input.size(); ++i) {
		if (convertToDay(input[i].date) >= temp) {

			BirthDays* tempData = new BirthDays;

			tempData->name = input[i].name;
			tempData->date = input[i].date;

			if (output.size() == 0 || convertToDay(output[0].date) == convertToDay(input[i].date)) {

				output.push_back(*tempData);
			}
			else {

				if (output.size() > 1) output.resize(1);

				output[0].name = tempData->name;

				output[0].date = tempData->date;
			}

			delete tempData;
			tempData = nullptr;
		}
	}
}

int main() {

	std::string userInput;

	std::vector<BirthDays> birthdaysFriends;

	while (true) {
		BirthDays* temp = new BirthDays;
		
		std::cout << "Enter friends' name: ";
		std::getline(std::cin, userInput);

		if (userInput == "end") break;

		temp->name = userInput;

		std::cout << "Enter his/her birthday in format YYYY/MM/DD: ";
		std::cin >> std::get_time(&temp->date, "%Y/%m/%d");
		std::cin.ignore();

		birthdaysFriends.push_back(*temp);

		delete temp;
		temp = nullptr;

	}

	if (birthdaysFriends.size() > 0) {
		std::cout << "=========================================" << std::endl;

		std::vector<BirthDays> nowDaysBirthDays;

		searchNearestBirthDay(birthdaysFriends, nowDaysBirthDays);

		if (nowDaysBirthDays.size() > 1) {

			std::cout << "There are not only one friend, that have nearest birthdays!" << std::endl;

			std::cout << "There are: " << std::endl;

			for (int i = 0; i < nowDaysBirthDays.size(); ++i) {

				std::cout << i + 1 << ". " << nowDaysBirthDays[i].name << std::endl;
			}
		}
		else if (nowDaysBirthDays.size() == 0) {

			std::cout << "There is no nearest birthday in the year!" << std::endl;
		}
		else {
			std::cout << nowDaysBirthDays[0].name << " have the nearest birthday!" << std::endl;
		}
	}
	else {
		std::cout << "There is no data!" << std::endl;
	}	

	std::cout << "===============THAT'S ALL FOLKS!====================" << std::endl;
}