#include <iostream>
#include <vector>

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*��� ����� ������ ����� ����� � ���� ����� -- ���������. ���������� ����� 
	� ������� 2 �����, ����� ������� ����� ������ ���������, � ������� �� �� �����. 
	�������������, ��� ������ ���� ���� ����� � ������� ��� � ����� ���������.
	������:
	a = {2, 7, 11, 15}. ��������� = 9
	2 + 7 = 9, ��� ��� ���� ������� ����� 2 � 7*/

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