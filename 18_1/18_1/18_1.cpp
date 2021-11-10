#include <iostream>
#include <vector>

void swap(std::vector<int>& vec, int* arr) {
	for (int i = 0; i < vec.size(); i++) {
		int temp = vec[i];
		vec[i] = *(arr + i);
		*(arr + i) = temp;
	}
}

int main() {
	std::vector<int> vec = { 1, 2, 3, 4 };
	int arr[] = { 2, 4, 6, 8 };

	swap(vec, arr);

	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}