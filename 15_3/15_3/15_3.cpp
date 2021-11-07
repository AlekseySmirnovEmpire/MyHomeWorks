#include <iostream>
#include <vector>


int main() {
	setlocale(LC_ALL, ".UTF8");

	/*С клавиатуры вводятся числа. Когда пользователь вводит -1 -- необходимо выводить 
	на экран пятое по возрастанию число среди введённых. Когда пользователь вводит -2 -- 
	программа завершает работу.
	Пример:
	ввод: 7 5 3 1 2 4 6 -1
	вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
	ввод: 1 1 1 -1
	вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
	ввод -2
	завершение программы*/

	std::vector<int> vec;
	int input;

	for (;;) {
		std::cout << "Input your number: ";
		std::cin >> input;

		if (input == -1) {
			for (int i = vec.size() - 1; i >= 0; i--) {
				int ind = 0;
				for (int j = 0; j < i; j++) {
					if (vec[j] > vec[ind]) ind = j;
				}
				int temp = vec[i];
				vec[i] = vec[ind];
				vec[ind] = temp;
			}
			std::cout << "5'th number is: " << vec[4] << std::endl;
		}
		else if (input == -2) break;
		else {
			vec.push_back(input);
		}
	}
}