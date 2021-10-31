#include <iostream>
#include <string>

bool isWinner(char arr[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (((arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) ||
					(arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]))
					&& arr[i][j] != ' ') {
				return true;
			}
		}
	}
	return false;
}

bool isCorrectInput(std::string input) {
	if (input.length() != 5) return false;
	else {
		if ((input[0] == 'X' || input[0] == 'O') && input[1] == ' ' &&
				(input[2] > '0' && input[2] <= '3') && input[3] == ' ' &&
				(input[4] > '0' && input[4] <= '3')) {
			return true;
		}
		else return false;
	}
}

void insertInput(char arr[][3], char posX, char posY, char symbol) {
	int x = (int)(posX - '0') - 1;
	int y = (int)(posY - '0') - 1;

	arr[x][y] = symbol;
}

void outputArray(char arr[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

bool isGameOver(char arr[][3]) {
	if (isWinner(arr)) return true;
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] == ' ') return false;
			}
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*Старинная-добрая игра на страницах всех школьных тетрадей. Поле размером 3х3 представлено 
	в виде двумерного массива с типом элементов char. Помните тот символьный тип из предыдущего 
	модуля? Теперь он нам и пригодится. Участвуют два игрока, которые ходят по очереди и ставят 
	в указанные ими в стандартном вводе координаты свой символ - ‘X’ или ‘O’ (буквы латинского 
	алфавита). Как только у одного из игроков будет установлено подряд три крестика или три нолика 
	- он побеждает. Если свободных клеток не осталось, а трёх совпадающих элементов не найдено - 
	объявляется ничья. Для простоты, мы не будем рассматривать диагональные совпадения, а только 
	строго вертикальные либо строго горизонтальные.

	Изначально всё поле инициализируется символом пробела - ‘ ‘. Это можно сделать сразу при 
	объявлении, либо с помощью вложенного цикла. На каждом ходе, при занятой клетке или при неверных 
	координатах этой клетки должно быть выведено сообщение и игрок должен указать координаты клетки 
	повторно. После каждого хода надо выводить в консоль текущее состояние всего игрового поля, для 
	наглядности.

	Сделаю ещё одну небольшую подсказку. Проверку на победу игрока, которую надо осуществлять после 
	каждого хода, можно сделать с помощью вложенного цикла, сразу проверяя и вертикаль и горизонталь 
	а как именно - попробуйте догадаться сами.*/

	char field[3][3];
	char winnerChar = ' ';
	std::string userInput;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = ' ';
		}
	}    // Вводим игровое поле, которое полностью состоит из пробелов.

	do {
		std::cout << "Input your symbol and it's position (SYMBOL ROW COL): ";
		std::getline(std::cin, userInput);
		if (isCorrectInput(userInput) && userInput[0] != winnerChar) {
			if (field[(userInput[2] - '0') - 1][(userInput[4] - '0') - 1] == ' ') {
				insertInput(field, userInput[2], userInput[4], userInput[0]);
				outputArray(field);
				winnerChar = userInput[0];
			}
			else {
				std::cout << "Wrong input, please, try again!" << std::endl;
			}
		}
		else {
			std::cout << "Wrong input, please, try again!" << std::endl;
		}
	} while (!isGameOver(field));

	if (isWinner(field)) {
		std::cout << (winnerChar == 'X' ? "First player won!\n" : "Second player won!\n");
	}
	else {
		std::cout << "Draw\n";
	}

	
}