#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

enum Numbers {
	DAYS = 60 * 60 * 60,
	HOURS = 60 * 60,
	MINUTES = 60
};

std::string getTime(long time) {

	int dayCount = 0, hoursCount = 0, minutesCount = 0;

	std::string result;

	while (time > DAYS) {
		++dayCount;
		time -= DAYS;
	}

	if (dayCount > 0) {
		result += (dayCount > 9) ? (std::to_string(dayCount) + " days ") : ("0" + std::to_string(dayCount) + " days ");
	}
	while (time > HOURS) {
		++hoursCount;
		time -= HOURS;
	}

	result += (hoursCount > 9) ? (std::to_string(hoursCount) + ":") : ("0" + std::to_string(hoursCount) + ":");

	while (time > MINUTES) {
		++minutesCount;
		time -= MINUTES;
	}

	result += (minutesCount > 9) ? (std::to_string(minutesCount) + ":") : ("0" + std::to_string(minutesCount) + ":");

	result += (time > 9) ? std::to_string(time) : ("0" + std::to_string(time));

	return result;
}

int main() {

	/*��������� ������� ��������� �������� ������� std::time, ���������� ���������� �������� ����� �������.

	������������ ��������������� � ���������� � ������� ������:

	������� begin �������� ������������ ����� ������. ����� ����� ���� ������� ������������ ������ ������
	�������� ������, ��� ������� �� ��������� ������ ��������. ���� ��� ���� ������ �����-�� ������ ������,
	���������� ������ ���� ������������� ��������� � ������ �����.
	������� end ����������� ������������ ������� ������. ���� ������� ������� ������ ���, �� ������� ������
	�� ������.
	������� status ������� �� ����� ���������� � ���� ����������� ������� � �������, ������� ���� �� ���
	���������. ����� ��������� �������� ������� ����������� ������, ���� ������� �������.
	������� exit ������� �� ���������. */


	std::string userInput = "";

	bool isAction = false;

	long tempTime;

	while (userInput != "exit") {

		std::cout << "Enter your command (exit to stop): " << std::endl;
		std::getline(std::cin, userInput);

		long curTime;

		if (userInput == "begin") {

			std::ofstream file("text.txt", std::ios::app);

			if (file.is_open()) {
				std::cout << "Which action you wanted to do: ";
				std::string answer;

				std::getline(std::cin, answer);

				curTime = std::time(nullptr);

				file << answer << ' ';

				if (isAction) {
					file << getTime(curTime - tempTime) << std::endl;

					file << answer << ' ';
				}
				else {

					file << answer << ' ';

					isAction = true;
				} 

				tempTime = curTime;

				file.close();
			}
			else {
				std::cout << "Error! File with notes not found!" << std::endl;
			}
		}
		else if (userInput == "status") {
			std::ifstream file("text.txt");

			if (file.is_open()) {

				file.seekg(0);
				while (!file.eof()) {
					char* temp = new char[21];

					file.read(temp, 20);

					if (file.gcount() < 20) {
						temp[file.gcount()] = 0;
					}
					else {
						temp[20] = 0;
					}

					std::cout << temp;
				}

				file.close();
			}
			else {
				std::cout << "You don't have any notes!" << std::endl;
			}
		}
		else {
			std::cout << "Wrong input!" << std::endl;
		}
	}
}