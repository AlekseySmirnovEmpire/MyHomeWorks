#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream message;
	message.open("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\19_1\\words.txt");

	std::string input;
	std::cout << "Input your word: ";
	std::cin >> input;

	int count = 0;

	while (!message.eof()) {
		std::string dataFile;
		message >> dataFile;
		
		if (input == dataFile) count++;
	}

	std::cout << "Your word occurs in file " << count << " time!" << std::endl;

	message.close();
}