#include "CommandList.h"
#include <fstream>
#include <iostream>

void save() {
	std::ofstream file("save_file.txt");

	if (file.is_open()) {

		for (int i = 0; i < 8; ++i) {
			file << read(i) << ' ';
		}

		std::cout << "File SAVED!" << std::endl;

	}
	else {
		std::cout << "Error! File not found!" << std::endl;
	}
}

void load() {
	std::ifstream file("save_file.txt");

	if (file.is_open()) {

		int* temp = new int;

		int* i = new int;
		*i = 0;

		while (!file.eof()) {

			file >> *temp;

			write(*i, *temp);

			++* i;
		}

		std::cout << "File LOADED!" << std::endl;

		delete temp;
		temp = nullptr;

		delete i;
		i = nullptr;
	}
	else {
		std::cout << "Error! File not found!" << std::endl;
	}
}