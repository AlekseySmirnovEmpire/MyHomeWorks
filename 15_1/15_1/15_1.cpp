#include <iostream>
#include <vector>

int main() {
	setlocale(LC_ALL, ".UTF8");
	/*Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, 
	что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.
	Пример:
	a = {-2,1,-3,4,-1,2,1,-5,4}
	Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, 
	сумма = 6. Необходимо вывести 3 и 6*/

	std::vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;

	int temp = 0, sum = array[0], iMax = 0, jMax = 0, tempIndex = -1;

	for (int i = 0; i < array.size(); i++) {
		temp += array[i];
		if (temp > sum) {
			sum = temp;
			iMax = tempIndex + 1;
			jMax = i;
		}
		if (temp < 0) {
			temp = 0;
			tempIndex = i;
		}
	}

	std::cout << iMax << ' ' << jMax << std::endl;
}