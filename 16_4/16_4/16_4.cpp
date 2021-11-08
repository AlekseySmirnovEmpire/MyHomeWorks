#include <iostream>
#include <string>
#include <sstream>

bool isCorrectInput(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] - '0' < 1 || input[i] - '0' > 7) return false;
	}
	return true;
}

enum notes {
	DO = 1 << 0,
	RE = 1 << 1,
	MI = 1 << 2,
	FA = 1 << 3,
	SOL = 1 << 4,
	LA = 1 << 5,
	TI = 1 << 6
};

int main() {
	/*Создать упрощённую модель механического пианино. Всего у данного пианино 
	- 7 клавиш, соответствуют они семи нотам. Каждая клавиша кодируется 
	уникальной битовой маской, которая записывается в enum. Вначале программы 
	пользователь вводит мелодию. Ввод осуществляется с помощью цифр на клавиатуре, 
	от 1 до 7 включительно (от ноты “до” до ноты “си”). В результате из чисел 
	может быть составлена любая комбинация нот. К примеру 512 или 154. 
	После ввода комбинации, вводится следующая. Всего таких комбинаций нот - 12. 
	Как только все комбинации были введены пользователем, мелодия проигрывается. 
	Для этого каждая комбинация нот последовательно выводится на экран. Однако, 
	на этот раз она печатается “красиво”, т.е. все ноты указываются словами, 
	а не цифрами. При этом слова разделяются пробелами.*/

	const int counter = 12;
	std::string userInput;
	std::string melody = "";

	for (int i = 0; i < counter; i++) {
		std::cout << "Input your " << std::to_string(i + 1) << " combination (from 1 to 7 for each note): ";
		std::cin >> userInput;

		while (!isCorrectInput(userInput)) {
			std::cout << "Wrong input, please, try again: ";
			std::cin >> userInput;
		}

		melody += userInput;
	} //Дали юзеру все 12 комбинаций записать

	for (int i = 0; i < melody.length(); i++) {
		int note = 1 << (int)(melody[i] - '1');
		if (note & DO) std::cout << "Do ";
		else if (note & RE) std::cout << "Re ";
		else if (note & MI) std::cout << "Mi ";
		else if (note & FA) std::cout << "Fa ";
		else if (note & SOL) std::cout << "Sol ";
		else if (note & LA) std::cout << "La ";
		else if (note & TI) std::cout << "Ti ";
	}
}