#include <iostream>
#include <string>
#include <cmath>

struct Vec
{
	double x = 0;
	double y = 0;
};

bool isCorrect(std::string& input) {
	return (input == "/help" || input == "/add" || input == "/subtract" || input == "/scale" || input == "/length" || input == "/normalize");
}

void showHelpMenu(std::string& input) {
	std::cout << "Type \"/add\" to sum two vectors;" << std::endl;
	std::cout << "Type \"/subtract\" to substract two vectors;" << std::endl;
	std::cout << "Type \"/scale\" to multipli vector with scalar;" << std::endl;
	std::cout << "Type \"/length\" to show vector's length;" << std::endl;
	std::cout << "Type \"/normalize\" to normalize vector;" << std::endl;

	std::cout << "Type your commad: ";
	std::getline(std::cin, input);

	while (!isCorrect(input) && input != "/help") {
		std::cout << "Wrong input, try again: " << std::endl;
		std::getline(std::cin, input);
	}
}

void sumAndSub(std::string& input) {

	Vec vectors[3];

	std::cout << "Input first vector (x y): ";
	std::cin >> vectors[0].x >> vectors[0].y;
	std::cin.ignore();

	std::cout << "Input second vector (x y): ";
	std::cin >> vectors[1].x >> vectors[1].y;
	std::cin.ignore();

	if (input == "/add") {
		vectors[2].x = vectors[0].x + vectors[1].x;
		vectors[2].y = vectors[0].y + vectors[1].y;
	}
	else {
		vectors[2].x = vectors[0].x - vectors[1].x;
		vectors[2].y = vectors[0].y - vectors[1].y;
	}

	std::cout << "Result is vector = {" << vectors[2].x << "," << vectors[2].y << "}" << std::endl;
}

void otherOperations(std::string& input) {
	Vec vector;
	
	std::cout << "Input vector (x y): ";
	std::cin >> vector.x >> vector.y;
	std::cin.ignore();

	if (input == "/scale") {
		std::cout << "Input scalar (s): ";
		double temp;
		std::cin >> temp;
		std::cin.ignore();

		std::cout << "Result = {" << vector.x * temp << "," << vector.y * temp << "}" << std::endl;
	}
	else if (input == "/length") {
		std::cout << "Result = " << std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2)) << std::endl;
	}
	else {
		double temp = std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));

		std::cout << "Result = {" << vector.x / temp << "," << vector.y / temp << "}" << std::endl;
	}
}

int main() {
	std::cout << "Input your command (\"/help\" for show all commands): ";
	std::string userInput;
	std::getline(std::cin, userInput);

	while (!isCorrect(userInput)) {
		std::cout << "Wrong input, try again: " << std::endl;
		std::getline(std::cin, userInput);
	}

	if (userInput == "/help") showHelpMenu(userInput);

	if (userInput == "/add" || userInput == "/subtract") sumAndSub(userInput);
	else otherOperations(userInput);
}