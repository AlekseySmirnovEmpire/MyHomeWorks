#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

	std::ifstream file;
	
	std::cout << "Input file directory (for example C:\\user\\text.txt): ";
	std::string userInput;
	std::cin >> userInput;

	file.open(userInput, std::ios::binary);

	while (!file.is_open()) {
		std::cout << "Wrong input, try again: ";
		std::cin >> userInput;
		file.open(userInput, std::ios::binary);
	}

	std::cout << "~~~~~~~~~~~~~~~File is open!~~~~~~~~~~~~~~~" << std::endl;

	char temp[21];
	while (!file.eof()) {
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