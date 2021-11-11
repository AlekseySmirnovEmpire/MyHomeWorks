#include <iostream>
#include <fstream>
#include <string>
#include <vector>


bool isGameOver(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != 0) return false;
	}
	return true;
}

void transformRotation(int rot, std::vector<int>& vec, int* sector) {
	while (rot > 13) {
		rot -= 13;
	}
	if (rot + *sector > 13) {
		*sector = (rot + *sector) - 13;
	}
	else {
		*sector = *sector + rot;
	}
	if (vec[*sector - 1] == 0) {
		bool isFound = false;
		for (int i = *sector; i < vec.size(); i++) {
			if (vec[i] != 0) {
				*sector = vec[i];
				vec[i] = 0;
				isFound = true;
				break;
			}
		}
		if (!isFound) {
			for (int i = 0; i < (*sector - 1); i++) {
				if (vec[i] != 0) {
					*sector = vec[i];
					vec[i] = 0;
					break;
				}
			}
		}
	}
	else {
		vec[*sector - 1] = 0;
	}
}

bool isCorrectAnswer(std::string ans, int sector) {

	std::ifstream answer;
	answer.open("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\19_5\\Answers\\" + std::to_string(sector) + ".txt");

	std::string temp;
	std::getline(answer, temp);

	answer.close();

	return ans == temp;
}

int main() {

	std::cout << "Welcome to our quize game! Player vs TV viewers!" << std::endl;

	int playersPoints = 0;
	int enemiesPoints = 0;
	int roundCount = 1;
	std::vector<int> sectors = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int sectorCount = 1;

	std::ifstream questions;

	questions.open("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\19_5\\questions.txt");

	while (!isGameOver(sectors)) {
		std::cout << "~~~~~~~~~~~~~~~Round " << std::to_string(roundCount) << "!~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "Input roulette rotation: ";
		int rotation;
		std::cin >> rotation;
		std::cin.ignore();

		while (rotation < 1) {
			std::cout << "Wrong! Input rotation again: ";
			std::cin >> rotation;
		}
		transformRotation(rotation, sectors, &sectorCount);

		std::cout << "Sector " << std::to_string(sectorCount) << " on roulette. In game! Your question is: " << std::endl;

		std::string temp;
		while (!questions.eof()) {
			questions >> temp;
			if (temp == "Quest" + std::to_string(sectorCount) + ":") {
				int pos = questions.tellg();
				questions.seekg(pos + 1);
				std::getline(questions, temp);
				std::cout << temp << std::endl;
				questions.seekg(0);
				break;
			}
		}

		std::string playerAnswer;
		std::cout << "Your answer is: ";
		std::getline(std::cin, playerAnswer);

		if (!isCorrectAnswer(playerAnswer, sectorCount)) {
			std::cout << "Sorry, but it's wrong answer. Plus one point to TV viwers!" << std::endl;
			enemiesPoints++;
		}
		else {
			std::cout << "Absolutely correct! Plus one point to player!" << std::endl;
			playersPoints++;
		}
		roundCount++;
	}
	questions.close();

	std::cout << "---------------------------------------------------------------------------" << std::endl;
	
	std::cout << "Final score: " << std::endl << std::to_string(playersPoints) << " - player score." << std::endl;
	std::cout << std::to_string(enemiesPoints) << " - TV viewers score." << std::endl;

	std::cout << (playersPoints > enemiesPoints ? "PLAYER WIN!\n" : "TV VIEWERS WIN!\n");
}