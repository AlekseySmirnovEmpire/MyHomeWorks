#include <iostream>
#include <string>
#include <sstream>

int main() {
	/*Надо написать небольшую программу. Из целой и дробной частей числа, 
	которые в отдельности вводит пользователь надо составить новое число 
	с плавающей точкой (типа double) и вывести это число обратно в консоль, 
	для проверки. Целая часть - это та, часть числа, которая находится 
	до точки (запятой), дробная - после.*/

	double firstPart;
	double secondPart;
	std::stringstream result;

	std::cout << "Input your first part: ";
	std::cin >> firstPart;

	std::cout << "Input your second part: ";
	std::cin >> secondPart;

	while (secondPart < 0) {
		std::cout << "Wrong input. Please, try again: ";
		std::cin >> secondPart;
	}

	result << firstPart << '.' << secondPart;

	double value = std::stod(result.str());

	std::cout << value << std::endl;
}