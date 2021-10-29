#include <iostream>

int main() {
	int arr[15];
	std::cout << "Input all numbers: ";

	for (int i = 0; i < 15; i++) {
		std::cin >> arr[i];
	}

	int sum = 0, min = arr[0], temp = 0;

	for (int i = 0; i < 15; i++) {
		sum += arr[i];

		if (arr[i] < min) min = arr[i];
	}

	for (int i = 0; i < 15; i++) {
		temp += i + min;
	}

	temp -= sum;

	std::cout << "Doubling number is: " << min + (14 - temp) << std::endl;

}