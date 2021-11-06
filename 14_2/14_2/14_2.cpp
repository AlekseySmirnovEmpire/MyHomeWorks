#include <iostream>
#include <string>

bool isWinner(char arr[][3]) {
	for (int i = 0; i < 3; i++) {
		if ((arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) ||
				(arr[0][i] != ' ' && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])) {
			return true;
		}
	}
	return false;
}

bool isCorrectInput(std::string input) {
	if (input.length() != 3) return false;

	return ((input[0] > '0' && input[0] <= '3') && (input[2] > '0' && input[2] <= '3')
		&& input[1] == ' ');
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
	std::string userInput;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = ' ';
		}
	}    // Вводим игровое поле, которое полностью состоит из пробелов.

	bool firstPlayerTurn = true;

	do {
		std::cout << "Input your symbol and it's position (ROW COL): ";
		std::getline(std::cin, userInput);
		if (isCorrectInput(userInput)) {
			int x = (int)(userInput[0] - '0') - 1;
			int y = (int)(userInput[2] - '0') - 1;
			if (field[x][y] == ' ') {
				field[x][y] = (firstPlayerTurn ? 'X' : 'O');
				outputArray(field);
				firstPlayerTurn = !firstPlayerTurn;
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
		std::cout << (firstPlayerTurn ? "Second player won!\n" : "First player won!\n");
	}
	else {
		std::cout << "Draw\n";
	}

	
}