#include <iostream>
#include <vector>

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*� ������� ������ ������������� ������� ������ ��� �� �������� (�������� �������). ��� ��, 
		� ������� ������ �������������, ������� ������ ������� (� ���� ��������), ������� ��������� �������. 
		���������� ������� �� ����� �������� ��������� �������.

		������:

		������ ��� �������� ���:  {2.5, 4.25, 3.0, 10.0}

		������ �������: {1, 1, 0, 3}, �� ���� ��� ������ �� ������� 1, � �� ������ � �������� 0 � 3.

		��������� ��������� ����� ����� 21.0*/

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