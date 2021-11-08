﻿#include <iostream>
#include <string>
#include <sstream>

int main() {
	/*Требуется создать небольшую программу для вычисления простых 
	действий с числами. При запуске программа ожидает пользовательского 
	ввода во временную переменную строку. После ввода строки, она 
	распарсивается на отдельные члены. Строка записывается в форме 
	“<число-1><действие><число-2>” (без пробелов). Оба числа - это 
	значения с плавающей точкой, повышенной точности (double). 
	Действие может быть одним из: +, -, /, *. Результат действия 
	выводится в стандартный вывод cout.*/

	double firstNumber, secondNumber, value;
	char action;
	std::string userInput;

	std::cout << "Input your expression: ";
	std::cin >> userInput;

	std::stringstream input;

	input << userInput;

	input >> firstNumber >> action >> secondNumber;

	if (action == '+') {
		value = firstNumber + secondNumber;
	}
	else if (action == '-') {
		value = firstNumber - secondNumber;
	}
	else if (action == '*') {
		value = firstNumber * secondNumber;
	}
	else if (action == '/') {
		value = firstNumber / secondNumber;
	}

	std::cout << value << std::endl;
}