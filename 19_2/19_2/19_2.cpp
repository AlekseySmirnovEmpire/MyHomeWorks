#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string transform(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '\\') {
			input.insert(i + 1, "\\");
			i++;
		}
	}
	return input;
}

int main() {

	std::ifstream file;
	
	std::cout << "Input file directory (for example C:\\user\\text.txt): ";
	std::string userInput;
	std::cin >> userInput;

	file.open(transform(userInput), std::ios::binary);

	while (!file.is_open()) {
		std::cout << "Wrong input, try again: ";
		std::cin >> userInput;
		file.open(transform(userInput), std::ios::binary);
	}

	std::cout << "~~~~~~~~~~~~~~~File is open!~~~~~~~~~~~~~~~" << std::endl;

	char temp;
	while (file.read((char*)&temp, sizeof(temp))) {
		std::cout << temp;
	}

	file.close();
}