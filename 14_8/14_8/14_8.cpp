#include <iostream>

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*��� ��-���� ��������� ������� ����� ������� ����������. ��������� �� ������, 
	�� ��� �������� ���������� ������ �� ���������������� ��������. � ��� ���� ��������� 
	���������� ��������, �������� 5�5 ��������. � ������ ������� ������������� ���� 
	(�������) ���������, ������������ ������ �������� � ��� 10 ������. ������� ������ 
	������� ������ ����� ������� ������������� ������� ���������. �������� ������ � 
	��������� ��������� ������ ������� � ����������� ����� �������������� ������� 
	(��� �������������� ����) ������ ���������� ����. ��� ��� ��� ��� ������ ���� 
	����������� � ���� ���������� �������. ��� �������������� ���� ����� ���� � ��� 
	��������� ������, ������� ���� ���������� � ���� ������ � �����. 0 � ��� ���������� 
	�������� �� ������ ������ � ������ �����, 1 � ������� ����. ������� ����� �� 0 �� 9 
	������������ � ����� ������� � ����������� �����.*/

	int height, aria[5][5][10], level;

	std::cout << "Input height of your blocks (from 0 to 10): " << std::endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			bool isRight = true;

			do {
				std::cin >> height;

				if (height < 0 || height > 10) {
					std::cout << "Wrong input. Try again: ";
					isRight = false;
				}
			} while (!isRight);

			for (int k = 0; k < 10; k++) {
				if (k < height) {
					aria[i][j][k] = 1;
				}
				else {
					aria[i][j][k] = 0;
				}
			}
		}
	}

	bool isCorrect = true;
	do {
		std::cout << "Choose the level of slice (from 0 to 9): ";
		std::cin >> level;

		if (level < 0 || level > 9) {
			isCorrect = false;
			std::cout << "Wrong input. Try again." << std::endl;
		} 

	} while (!isCorrect);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << aria[i][j][level] << ' ';
		}
		std::cout << std::endl;
	}


}