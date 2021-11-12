#include <iostream>
#include <fstream>
#include <ctime>

enum typeOfError {
	FILE_NOT_FOUND = 1,
	WRONG_INPUT,
	NOT_ENOUGHT_MONEY
};

void createDataBin() {
	std::srand(std::time(nullptr));

	std::ofstream data("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_4\\data.bin", std::ios::binary);

	int count[] = { 5000, 2000, 1000, 500, 200, 100 };
	int money[6][2];

	for (int i = 0; i < 6; i++) {
		money[i][0] = count[i];
		money[i][1] = rand() % 10 + 1;
	}
	data.write((char*)&money, sizeof(money));
	
	data.close();
}

bool isCorrectSum(int sum, int arr[][2]) {
	int temp = 0;

	for (int i = 0; i < 6; i++) {
		temp += arr[i][1] * arr[i][0];
	}

	return (sum <= temp && sum >= 100 && sum % 100 == 0);
} 

void moneyGive(int* sum, int nominal, int* amount) {
	int temp = 0;
	
	while (*sum >= nominal && (*amount - temp) > 0) {
		*sum -= nominal;
		temp++;
	}
	*amount -= temp;
	
	std::cout << "Given " << temp << " banknotes with " << nominal << " nominal!" << std::endl;
}

void giveMoneyATM(int* sum) {
	int moneyCount[6][2];

	std::ifstream outData("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_4\\data.bin", std::ios::binary);
	outData.read((char*)moneyCount, sizeof(moneyCount));
	outData.close();

	for (int i = 0; i < 6; i++) {
		moneyGive(sum, moneyCount[i][0], &moneyCount[i][1]);
	}

	std::ofstream inFile("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_4\\data.bin", std::ios::binary);
	inFile.write((char*)&moneyCount, sizeof(moneyCount));
	inFile.close();
}

int main() {
	std::ifstream data("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_4\\data.bin", std::ios::binary);

	if (!data.is_open()) {
		std::cout << "Error! File not found!" << std::endl;
		createDataBin();
		return FILE_NOT_FOUND;
	}

	std::cout << "~~~~~~~~~~~~~~~~ATM~~~~~~~~~~~~~~~~" << std::endl;

	int atm[6][2];
	char answer;

	data.read((char*)atm, sizeof(atm));
	data.close();

	std::cout << "Nominal\tCount" << std::endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << atm[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	std::cout << "Input \"+\" to top up the ATM with banknotes or \"-\" to start withdrawing money: ";
	std::cin >> answer;
	std::cin.ignore();

	if (answer == '+') {
		for (int i = 0; i < 6; i++) {
			atm[rand() % 6][1] += rand() % 10 + 1;
		}

		std::ofstream inData("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\20_4\\data.bin", std::ios::binary);
		inData.write((char*)&atm, sizeof(atm));
		inData.close();

	}
	else if (answer == '-') {
		int userInput;
		std::cout << "Input the withdrawal amount: ";
		std::cin >> userInput;
		std::cin.ignore();

		if (isCorrectSum(userInput, atm)) {
			giveMoneyATM(&userInput);
		}
		else {
			std::cout << "Error! ATM doen't have such amount of money!" << std::endl;
			return NOT_ENOUGHT_MONEY;
		}
	}
	else {
		std::cout << "Error! Wrong input!" << std::endl;
		data.close();
		return WRONG_INPUT;
	}

	std::cout << "-------------Goodbye!-----------------" << std::endl;
}