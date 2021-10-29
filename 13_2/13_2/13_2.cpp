#include <iostream>
#include <vector>

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*С помощью списка инициализации задаётся вектор цен на продукты (дробными числами). Так же, 
		с помощью списка инициализации, задаётся вектор покупок (в виде индексов), которые совершает человек. 
		Необходимо вывести на экран итоговую стоимость покупок.

		Пример:

		Вектор цен выглядит так:  {2.5, 4.25, 3.0, 10.0}

		Вектор покупок: {1, 1, 0, 3}, то есть два товара по индексу 1, и по одному — индексов 0 и 3.

		Суммарная стоимость будет равна 21.0*/

	std::vector<float> prices;
	std::cout << "Input prices count (write \"-1\" to stop):\n";
	float input = 0;

	for (;;) {
		std::cin >> input;
		if (input == -1.f) break;
		prices.push_back(input);
	}

	std::vector<int> indexes;
	std::cout << "Input your indexes (write \"-1\" to stop):\n";
	int index;

	for (;;) {
		std::cin >> index;
		if ((index > prices.size() - 1 || index < 0)) {
			if (index == -1) break;
			else {
				std::cout << "Incorrect input!\n";
				continue;
			}
		}
		indexes.push_back(index);
	}

	float sum = 0.f;

	for (int i = 0; i < indexes.size(); i++) {
		sum += prices[indexes[i]];
	}

	std::cout << "Total cost: " << sum;
}