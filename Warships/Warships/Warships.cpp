#include <iostream>
#include <string>
#include <cmath>

void initPlayersBoard(char arr[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 'O';
		}
	}
}

void showPlayerBoard(char arr[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------" << std::endl;
}

bool isBoardEmpty(int ships[4]) {
	for (int i = 0; i < 4; i++) {
		if (ships[i] != 0) return false;
	}
	return true;
}

bool isRightShip(std::string input) {
	if (input.length() == 3) return true;
	else {
		int x1 = (int)(input[0] - '0');
		int x2 = (int)(input[4] - '0');
		int y1 = (int)(input[2] - '0');
		int y2 = (int)(input[6] - '0');
		int horizShip = std::abs(x1 - x2) + 1;
		int verticShip = std::abs(y1 - y2) + 1;
		if ((horizShip == 1 && verticShip == 1) || horizShip > 4 || verticShip > 4 || (x1 != x2 && y1 != y2)) return false;
		else return true;
	}
}        // Проверяет корректность коробля самого: если >4 палуб, он диалогнален или через 2 кординаты ввели однопалубник - false.

bool isCorrectInput(std::string input) {
	if (input.length() == 3) {
		int x = (int)(input[0] - '0');
		int y = (int)(input[2] - '0');
		if (x < 0 || x > 9 || y < 0 || y > 9 || input[1] != ',') return false;
		else return true;
	}
	else if (input.length() == 7) {
		int x1 = (int)(input[0] - '0');
		int y1 = (int)(input[2] - '0');
		int x2 = (int)(input[4] - '0');
		int y2 = (int)(input[6] - '0');
		if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9 || 
				(input[1] != ',' && input[1] != input[5]) || input[3] != '-') return false;
		else return true;
	}
	else return false;
}

bool isEmptySpace(std::string input, char arr[][10]) {
	if (input.length() == 3) {
		int x = (int)(input[0] - '0');
		int y = (int)(input[2] - '0');
		if (arr[9 - y][x] == 'X') return false;
	}
	else {
		int x1 = (int)(input[0] - '0');
		int y1 = (int)(input[2] - '0');
		int x2 = (int)(input[4] - '0');
		int y2 = (int)(input[6] - '0');
		int xmax = x1 > x2 ? x1 : x2;
		int xmin = x1 > x2 ? x2 : x1;
		int ymax = y1 > y2 ? y1 : y2;
		int ymin = y1 > y2 ? y2 : y1;
		if (x1 != x2) {
			for (int i = xmin; i < xmax + 1; i++) {
				if (arr[9 - y1][i] == 'X') return false;
			}
		}
		else {
			for (int i = ymin; i < ymax; i++) {
				if (arr[9 - i][x1] == 'X') return false;
			}
		}
	}
	return true;
}

bool isEmptyShips(std::string input, int ship[4]) {
	if (input.length() == 3) {
		if (ship[0] == 0) return false;
	}
	else {
		int x1 = (int)(input[0] - '0');
		int y1 = (int)(input[2] - '0');
		int x2 = (int)(input[4] - '0');
		int y2 = (int)(input[6] - '0');

		if (((x1 != x2) && ship[std::abs(x2 - x1)] == 0) ||
			((y1 != y2) && ship[std::abs(y2 - y1)] == 0)) return false;
	}
	return true;
}

void correctShipsCount(std::string input, int ships[4]) {
	if (input.length() == 3) {
		ships[0]--;
	}
	else {
		int x1 = (int)(input[0] - '0');
		int y1 = (int)(input[2] - '0');
		int x2 = (int)(input[4] - '0');
		int y2 = (int)(input[6] - '0');

		if (x1 != x2) {
			ships[std::abs(x2 - x1)]--;
		}
		else {
			ships[std::abs(y2 - y1)]--;
		}
	}
}

void inputPlayerBoard(std::string input, char arr[][10]) {
	if (input.length() == 3) {
		int x = input[0] - '0';
		int y = input[2] - '0';

		arr[9 - y][x] = 'X';
	}
	else {
		int x1 = (int)(input[0] - '0');
		int y1 = (int)(input[2] - '0');
		int x2 = (int)(input[4] - '0');
		int y2 = (int)(input[6] - '0');
		int xmax = x1 > x2 ? x1 : x2;
		int xmin = x1 > x2 ? x2 : x1;
		int ymax = y1 > y2 ? y1 : y2;
		int ymin = y1 > y2 ? y2 : y1;
		if (x1 != x2) {
			for (int i = xmin; i <= xmax; i++) {
				arr[9 - y1][i] = 'X';
			}
		}
		else {
			for (int i = ymin; i <= ymax; i++) {
				arr[9 - i][x1] = 'X';
			}
		}
	}
}

// FOR GAME:

bool isGameOver(char arr[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 'X') return false;
		}
	}
	return true;
}

bool isCorrect(std::string input) {
	if (input.length() == 3) {
		int x = input[0] - '0';
		int y = input[2] - '0';
		if (x < 0 || x > 9 || y < 0 || y > 9 || input[1] != ',') return false;
		else return true;
	}
	return false;
}

void playerTurn(std::string input, char arr[][10]) {
	int x = input[0] - '0';
	int y = input[2] - '0';

	if (arr[9 - y][x] == 'O') {
		arr[9 - y][x] = '-';
		std::cout << "Miss!" << std::endl;
	}
	else if (arr[9 - y][x] == 'X') {
		arr[9 - y][x] = '+';
		std::cout << "Boom!" << std::endl;
	}
	else {
		std::cout << "You've hit this area later." << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, ".UTF8");
	
	/*Требуется реализовать упрощённую игру в Морской бой. Игровое поле размером 10 на 10 клеток.
	Участвует двое игроков. В арсенале каждого из них: 4 маленьких кораблика размером в одну клетку,
	3 небольших корабля размером в две клетки, 2 средних корабля размером в три клетки и один
	большой корабль размером в четыре клетки. Для простоты, клетки поля пронумерованы по вертикали
	от 0 до 9, и по горизонтали также от 0 до 9. Мы не будем использовать классические наименования
	клеток, такие как B4, C6, а просто два индекса. Вначале игроки по очереди расставляют корабли,
	начиная с самых маленьких и заканчивая большими. Маленькие корабли в одну клетку расставляются
	с помощью указания лишь одной клетки-точки на поле, к примеру 2,1. Корабли размерностью от двух
	клеток и выше, расставляются с помощью координат их начала и конца, к примеру: 0,1 - 0,3.
	Корабли могут быть установлены только строго вертикально, или горизонтально. Установка корабля
	по диагонали — недопустимо, в случае которого об этом тоже надо сообщить пользователю.
	Если корабль не может быть размещён на заданных клетках из-за того, что он столкнётся с другим
	кораблём (окажется на его клетках) или выйдет за пределы поля вообще, то игроку должно быть
	сделано предупреждение, после которого он должен переставить корабль на новые валидные координаты.
	Замечу, в нашем упрощённом варианте игры, мы не будем обсчитывать соприкосновения кораблей друг
	с другом, а потому корабли вполне можно будет размещать друг к другу вплотную — борт к борту.
	После того как все корабли были расставлены начинается игра. Игроки по очереди атакуют друг друга,
	называя координаты выстрела. После выстрела, в консоль выводится информация о его результате:
	попал или мимо. Если выстрел успешен, клетка, на которой был корабль (или его фрагмент) затирается
	и становится пустой. Игра заканчивается тогда, когда все корабли одной из сторон будут полностью
	уничтожены. Как только это произойдёт в консоль выводится информация с номером игрока, который
	победил.*/

	char firstPlayerBoard[10][10];
	initPlayersBoard(firstPlayerBoard);
	char secondPlayerBoard[10][10];
	initPlayersBoard(secondPlayerBoard);

	bool firstPlayerTurn = true;
	bool isBoardFull = false;
	std::string userInput;
	
	int firstPlayerShips[4] = { 4,3,2,1 };
	int secondPlayerShips[4] = { 4,3,2,1 };

	do {
		std::cout << "Enter the coordinates of the ship's location" <<	(firstPlayerTurn ? " FIRST PLAYER " : " SECOND PLAYER ") <<
				"(\"x,y\" for one-deck ship or \"x1,y1-x2,y2\" without spaces for multy-deck from 0 to 9 for each: ";
		std::getline(std::cin, userInput);

		if (firstPlayerTurn) {
			while (!(isCorrectInput(userInput) && isRightShip(userInput) && isEmptyShips(userInput, firstPlayerShips) 
					&& isEmptySpace(userInput, firstPlayerBoard))) {
				std::cout << "Wrong input! Please, try again: ";
				std::getline(std::cin, userInput);
			}

			correctShipsCount(userInput, firstPlayerShips);
			std::cout << "First player's ships left (from 1- to 4-deck):" << std::endl;
			for (int i = 0; i < 4; i++) {
				std::cout << firstPlayerShips[i] << ' ';
			}
			std::cout << std::endl;

			inputPlayerBoard(userInput, firstPlayerBoard);

			showPlayerBoard(firstPlayerBoard);

			firstPlayerTurn = false;
		}    //First player input his ships
		else {
			while (!(isCorrectInput(userInput) && isRightShip(userInput) && isEmptyShips(userInput, secondPlayerShips) 
					&& isEmptySpace(userInput, firstPlayerBoard))) {
				std::cout << "Wrong input! Please, try again: ";
				std::getline(std::cin, userInput);
			}

			correctShipsCount(userInput, secondPlayerShips);
			std::cout << "Second player's ships left (from 1- to 4-deck):" << std::endl;
			for (int i = 0; i < 4; i++) {
				std::cout << secondPlayerShips[i] << " ";
			}
			std::cout << std::endl;

			inputPlayerBoard(userInput, secondPlayerBoard);

			showPlayerBoard(secondPlayerBoard);

			firstPlayerTurn = true;
		}   //SecondPlayer input his ships

		isBoardFull = (isBoardEmpty(firstPlayerShips) && isBoardEmpty(secondPlayerShips));
	} while (!isBoardFull); //Input all ships

	firstPlayerTurn = true;

	do {
		std::cout << "Game start!" << std::endl;
		std::cout << (firstPlayerTurn ? " FIRST PLAYER " : " SECOND PLAYER ") << "enter x,y where to shot: " << std::endl;
		std::getline(std::cin, userInput);

		while (!isCorrect(userInput)) {
			std::cout << "Wrong input, try again: ";
			std::getline(std::cin, userInput);
		}

		if (firstPlayerTurn) {
			playerTurn(userInput, firstPlayerBoard);
		}
		else {
			playerTurn(userInput, secondPlayerBoard);
		}

		firstPlayerTurn = !firstPlayerTurn;

	} while (isGameOver(firstPlayerBoard) || isGameOver(secondPlayerBoard)); //Game

	std::cout << (firstPlayerTurn ? "SECOND PLAYER WON!" : "FIRST PLAYER WON!") << std::endl;
}