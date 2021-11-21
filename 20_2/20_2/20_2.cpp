#include <iostream>
#include <fstream>
#include <ctime>

int main() {
	std::srand(std::time(nullptr));
	int height;
	int weight;
	
	std::cout << "Input height and weight of your picture (h w): ";
	std::cin >> height >> weight;

	std::ofstream file("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_2\\pic.txt");

	if (!file.is_open()) {
		std::cout << "Error! File not found!" << std::endl;
	}
	else {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < weight; j++) {
				bool temp = rand() % 2;
				file << temp;
			}
			file << std::endl;
		}

		file.close();
	}
}