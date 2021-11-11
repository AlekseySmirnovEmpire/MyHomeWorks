#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
	std::ifstream statement;
	statement.open("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\19_3\\text.txt");

	if (statement.is_open()) {
		std::cout << "~~~~~~~~~~~~~~File is open!~~~~~~~~~~~~~~" << std::endl;
		std::string firstName;
		std::string lastName;
		std::string dump;
		unsigned int money;
		unsigned int totalMoney;

		statement >> firstName >> lastName >> money >> dump;

		totalMoney = money;

		while (!statement.eof()) {
			unsigned int temp;
			int position = statement.tellg();

			statement >> dump >> dump >> temp >> dump;

			totalMoney += temp;
			
			if (temp > money) {
				statement.seekg(position);
				statement >> firstName >> lastName >> money >> dump;
			}
		}

		std::cout << "Total money payed: " << totalMoney << std::endl;
		std::cout << firstName << ' ' << lastName << " have maximum of all payed " << money << "!" << std::endl;
	}
	else {
		std::cout << "Error! File not found!" << std::endl;
	}

	statement.close();

	if (!statement.is_open()) std::cout << "~~~~~~~~~~~~~~File is close!~~~~~~~~~~~~~~" << std::endl;
}