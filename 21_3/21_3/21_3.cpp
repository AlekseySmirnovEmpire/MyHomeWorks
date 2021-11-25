#include <iostream>
#include <string>
#include <cmath>
#include <vector>

struct Vec
{
	double x = 0;
	double y = 0;
};

bool isCorrect(std::string& input) {
	return (input == "/help" || input == "/add" || input == "/subtract" || input == "/scale" || input == "/length" || input == "/normalize");
}

void sumVector(Vec& vec) {

	Vec* vector1 = new Vec;
	Vec* vector2 = new Vec;

	std::cout << "Input first vector (x y): ";
	std::cin >> vector1->x >> vector1->y;
	std::cin.ignore();

	std::cout << "Input second vector (x y): ";
	std::cin >> vector2->x >> vector2->y;
	std::cin.ignore();

	vec.x = vector1->x + vector2->x;
	vec.y = vector1->y + vector2->y;

	delete vector1;
	vector1 = nullptr;

	delete vector2;
	vector2 = nullptr;
}

void subVector(Vec& vec) {

	Vec* vector1 = new Vec;
	Vec* vector2 = new Vec;

	std::cout << "Input first vector (x y): ";
	std::cin >> vector1->x >> vector1->y;
	std::cin.ignore();

	std::cout << "Input second vector (x y): ";
	std::cin >> vector2->x >> vector2->y;
	std::cin.ignore();

	vec.x = vector1->x - vector2->x;
	vec.y = vector1->y - vector2->y;

	delete vector1;
	vector1 = nullptr;

	delete vector2;
	vector2 = nullptr;
}

void scaleVec(Vec& vec) {

	std::cout << "Input vector (x y): ";
	std::cin >> vec.x >> vec.y;
	std::cin.ignore();

	std::cout << "Input scalar (s): ";
	double* temp = new double;
	std::cin >> *temp;
	std::cin.ignore();

	vec.x *= *temp;
	vec.y *= *temp;

	delete temp;
	temp = nullptr;
}

double lengthVec(Vec& vec) {

	return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
}

void normVec(Vec& vec) {

	vec.x /= std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));

	vec.y /= std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));

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

int main() {
	std::cout << "Input your command (\"/help\" for show all commands): ";
	std::string userInput;
	std::getline(std::cin, userInput);

	Vec vector;

	while (!isCorrect(userInput)) {
		std::cout << "Wrong input, try again: " << std::endl;
		std::getline(std::cin, userInput);
	}

	if (userInput == "/help") showHelpMenu(userInput);

	if (userInput == "/add") {
		sumVector(vector);
		std::cout << "Result = {" << vector.x << ',' << vector.y << '}' << std::endl;
	}
	else if (userInput == "/subtract") {
		subVector(vector);
		std::cout << "Result = {" << vector.x << ',' << vector.y << '}' << std::endl;
	}
	else if (userInput == "/scale") {
		scaleVec(vector);
		std::cout << "Result = {" << vector.x << ',' << vector.y << '}' << std::endl;
	}
	else if (userInput == "/length") {
		std::cout << "Length = " << std::to_string(lengthVec(vector)) << std::endl;
	}
	else {
		normVec(vector);
		std::cout << "Result = {" << vector.x << ',' << vector.y << '}' << std::endl;
	}
}