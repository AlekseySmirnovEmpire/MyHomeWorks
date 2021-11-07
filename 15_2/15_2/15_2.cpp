#include <iostream>
#include <vector>

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*Вам даётся массив целых чисел и одно число -- результат. Необходимо найти 
	в массиве 2 числа, сумма которых будет давать результат, и вывести их на экран. 
	Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
	Пример:
	a = {2, 7, 11, 15}. Результат = 9
	2 + 7 = 9, так что надо вывести числа 2 и 7*/

	std::vector<int> array = { 2, 7, 11, 15, 6, 10, 8, 12 };

	int a = 0, b = 0, result;

	std::cout << "Input result: ";
	std::cin >> result;

	for (int i = 0; i < array.size(); i++) {
		for (int j = i; j < array.size(); j++) {
			if (array[i] + array[j] == result && i != j) {
				a = array[i];
				b = array[j];
			}
		}
	}

	std::cout << "Number 1: " << a << std::endl << "Number 2: " << b << std::endl;
}