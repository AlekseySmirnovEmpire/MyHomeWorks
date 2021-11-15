#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream message;
	message.open("words.txt");

	if (!message.is_open()) {
	std::cout << "Error! File not found!" << std::endl;
	}
	else {
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
}