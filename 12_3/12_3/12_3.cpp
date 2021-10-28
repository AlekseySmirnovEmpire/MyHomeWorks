#include <iostream>

int main() {
	float numbers[15];
	std::cout << "Input your numbers:" << std::endl;

	for (int i = 0; i < 15; i++) {
		std::cin >> numbers[i];
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 14; j++) {
			if (numbers[j] > numbers[j + 1]) {
				float temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}//Ну тут в самом условии прям просят так отсортировать пузырьком

	std::cout << std::endl << "Output: " << std::endl;

	for (int i = 0; i < 15; i++)
		std::cout << numbers[i] << std::endl;
}