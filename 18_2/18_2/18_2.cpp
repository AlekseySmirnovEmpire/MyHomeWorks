#include <iostream>

int jump(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	return (jump(n - 3) + jump(n - 2) + jump(n - 1));
}

int main() {
	int number;
	
	std::cout << "Input number: ";
	std::cin >> number;

	std::cout << jump(number) << std::endl;
}