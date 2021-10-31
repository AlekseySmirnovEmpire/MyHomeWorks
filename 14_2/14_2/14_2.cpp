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

	/*���������-������ ���� �� ��������� ���� �������� ��������. ���� �������� 3�3 ������������ 
	� ���� ���������� ������� � ����� ��������� char. ������� ��� ���������� ��� �� ����������� 
	������? ������ �� ��� � ����������. ��������� ��� ������, ������� ����� �� ������� � ������ 
	� ��������� ��� � ����������� ����� ���������� ���� ������ - �X� ��� �O� (����� ���������� 
	��������). ��� ������ � ������ �� ������� ����� ����������� ������ ��� �������� ��� ��� ������ 
	- �� ���������. ���� ��������� ������ �� ��������, � ��� ����������� ��������� �� ������� - 
	����������� �����. ��� ��������, �� �� ����� ������������� ������������ ����������, � ������ 
	������ ������������ ���� ������ ��������������.

	���������� �� ���� ���������������� �������� ������� - � �. ��� ����� ������� ����� ��� 
	����������, ���� � ������� ���������� �����. �� ������ ����, ��� ������� ������ ��� ��� �������� 
	����������� ���� ������ ������ ���� �������� ��������� � ����� ������ ������� ���������� ������ 
	��������. ����� ������� ���� ���� �������� � ������� ������� ��������� ����� �������� ����, ��� 
	�����������.

	������ ��� ���� ��������� ���������. �������� �� ������ ������, ������� ���� ������������ ����� 
	������� ����, ����� ������� � ������� ���������� �����, ����� �������� � ��������� � ����������� 
	� ��� ������ - ���������� ���������� ����.*/

	char field[3][3];
	char winnerChar = ' ';
	std::string userInput;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = ' ';
		}
	}    // ������ ������� ����, ������� ��������� ������� �� ��������.

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