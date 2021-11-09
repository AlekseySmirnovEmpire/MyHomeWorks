#include <iostream>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a;
	std::cout << "Input a: ";
	std::cin >> a;

	int b;
	std::cout << "Input b: ";
	std::cin >> b;

	swap(&a, &b);

	std::cout << "----SWAP----" << std::endl << "a = " << a << std::endl << "b = " << b << std::endl;
}