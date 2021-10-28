#include <iostream>

int main() {
	int arr[15];
	std::cout << "Input all numbers: ";

	for (int i = 0; i < 15; i++) {
		std::cin >> arr[i];
	}

	int temp;
	bool find = false;

	for (int i = 0; i < 15 && !find; i++) {
		for (int j = 0; j < 14; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (arr[i] == arr[i - 1] && (i > 0)) {
			std::cout << "Number wrote twice: " << arr[i];
			find = true;
		}
	}//Сортировка пузырьком + поиск числа

	/* Пузырьком делаем сортировку, потому что по условию надо как можно меньше памяти использовать*/

}