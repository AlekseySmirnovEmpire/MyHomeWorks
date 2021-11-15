#include <iostream>
#include <fstream>
#include <string>

bool isFilePNG(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '.') {
			if (input.substr(i, 4) != ".png") return false;
		}
	}
	return true;
}

int main() {
	std::string path;

	std::ifstream file;

	std::cout << "Input path to your file (exm. C:\\user\\image.png): ";
	std::cin >> path;

	while (!isFilePNG(path)) {
		std::cout << "Wrong file! Expected PNG file \"*.png\". Please, try again: ";
		std::cin >> path;
	}
	
	file.open(path, std::ios::binary);

	while (!file.is_open()) {
		std::cout << "Error! File not found! Try again: ";
		std::cin >> path;
		file.open(path, std::ios::binary);
	}

	std::cout << "~~~~~~~~~~~~~File is OPEN!~~~~~~~~~~~~~" << std::endl;

	char temp[4];
	file.read(temp, sizeof(temp));

	if ((int)(temp[0]) != -119 || temp[1] != 'P' || temp[2] != 'N' || temp[3] != 'G') {
		std::cout << "This file NOT PNG!" << std::endl;
	}
	else {
		std::cout << "This file IS PNG!" << std::endl;
	}

	file.close();

	std::cout << "~~~~~~~~~~~~~File is CLOSE!~~~~~~~~~~~~~" << std::endl;
}