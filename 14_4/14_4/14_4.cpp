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

	/*Требуется реализовать небольшую программу для сравнения двух двумерных матриц размерами 4х4 
	на предмет их полного равенства. Программа принимает на вход две целочисленные матрицы A и B, 
	которые вводятся с помощью std::cin и сравнивает их на предмет полного равенства. Если матрицы 
	равны, то об этом сообщается в стандартном выводе. Алгоритм должен быть по возможности оптимальным 
	и не проводить лишних операций.*/

	int a[4][4], b[4][4];

	std::cout << "Input first matrix 4x4: " << std::endl;

	inputArray(a);

	std::cout << "Input second matrix 4x4: " << std::endl;

	inputArray(b);

	std::cout << (arrayComparison(a, b) ? "They're totaly equal!\n" : "They're different.\n");
}