#include <iostream>
#include <string>

void showBubbles(bool arr[][12], bool isOver, int counter) {
	if (counter == 0) isOver = true;
	else {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				std::cout << (arr[i][j] == true ? "o " : "x ");
			}
			std::cout << std::endl;
		}
		std::cout << "_______________________\n";
	}
}

void popIt(bool arr[][12], int x, int y, int counter) {

	x--;
	y = 12 - y;

	if (arr[y][x] = true) {
		arr[y][x] = false;
		std::cout << "POP!" << std::endl;
		counter--;
	}
}

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*����� ������� �� ����� �������� ����. ����� ��� �������� ��������� ����� � �������. 
	����� � ������� 12 �� 12 �������-���������. ��������� ������ �������� � ��� ������ ���� 
	�� �����, ���� ���, �.�. true ��� false (��� ������� bool). ��� ������, ��������� 
	����������� ��������� ������� ������������� ������� ��������� ���������� � ��������� 
	����� �������, �.�. ��� �������� true. �� ��� ������ ����� ������.

	��������� ����������� � ���������������� ������� ����� �������� ���������. ����� ������ 
	����� �������� ���� ���������� ������������ ��������� ��� �����: o � ��� ����� ������, 
	x � ��������. ��� ���� ���� �������� � ��������� �������. ����, ��� �������� ���� �������. 
	������������ ������ ��� ����������: ���������� ������ ������� � ����� �������������� �������. 
	���� ��������� ������� ������� ������ ���� ����������� � ������� ��������� �������, 
	��� ��������� ������ ����������� �� �� ����������, ��� ��� � � ������ ��������� ��������� 
	�������� � ����� ������ ���� �������� ������. ����� ������� ������� ������, ������� �� ��� 
	��� ������ �� ����, � ������� ������ ���������� ��������� �Pop!�.

	������� ������ ������������ �� ���������� ��������. ��� ������ ��� ������� ���������, ��������� 
	����������� ����������. � ��������, �� ������ ���������� ��������� � ����� ������� �� ����������� 
	��������� �����, �.�. ��� ����������� ����� ������� �������.*/

	bool bubbles[12][12];  //bool lumpySpacePrinces ���� �� ���������� ��������, ��?

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			bubbles[i][j] = true;
		}
	}
	bool isOver = false;
	int counter = 12 * 12;

	showBubbles(bubbles, isOver, counter);

	int x, y;
	
	do {
		bool isCorrect = true;
		do {
			std::cout << "Input position of bubble you wish to pop (X Y): ";
			std::cin >> x >> y;
			if ((x > 12 || x < 1) && (y > 12 || y < 1)) {
				isCorrect = false;
				std::cout << "Wrong input, please, try again";
			}
		} while (!isCorrect);
		
		popIt(bubbles, x, y, counter);

		showBubbles(bubbles, isOver, counter);

	} while (!isOver);




}