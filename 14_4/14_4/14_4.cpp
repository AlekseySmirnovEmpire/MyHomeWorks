#include <iostream>

void inputArray(int arr[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> arr[i][j];
		}
	}
}

bool arrayComparison(int arr1[][4], int arr2[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr1[i][j] != arr2[i][j]) return false;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*��������� ����������� ��������� ��������� ��� ��������� ���� ��������� ������ ��������� 4�4 
	�� ������� �� ������� ���������. ��������� ��������� �� ���� ��� ������������� ������� A � B, 
	������� �������� � ������� std::cin � ���������� �� �� ������� ������� ���������. ���� ������� 
	�����, �� �� ���� ���������� � ����������� ������. �������� ������ ���� �� ����������� ����������� 
	� �� ��������� ������ ��������.*/

	int a[4][4], b[4][4];

	std::cout << "Input first matrix 4x4: " << std::endl;

	inputArray(a);

	std::cout << "Input second matrix 4x4: " << std::endl;

	inputArray(b);

	std::cout << (arrayComparison(a, b) ? "They're totaly equal!\n" : "They're different.\n");
}