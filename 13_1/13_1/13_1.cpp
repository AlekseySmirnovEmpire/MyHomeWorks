#include <iostream>
#include <vector>


int main() {
	setlocale(LC_ALL, ".UTF8");
	/*������������ ������ � ���������� ����� n, ����� -- n ����� �����, ������� ����� �������� � ������.

	����� ������������ ������ ��� ���� ��������. ����� ������� �� ������� ��� ��������, ������� ����� ������� ��������, � ������� �������� ��������� �������

	������:

	������������ ��� 5, ����� ����� 1, 3, 3, 5, 1. � ����� -- ����� 3. ����������, ����� � ������� �������� ����� 1, 5, 1, ������� ���� ������� �� �� �����.*/

	int n;
	std::cout << "Input numbers amount: ";
	std::cin >> n;

	std::vector<int> vec(n);

	std::cout << "Input numbers count:\n";

	for (int i = 0; i < vec.size(); i++) {
		std::cin >> vec[i];
	}
	std::cout << "Yout current array of numbers: ";
	
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Input your number: ";
	int userNumber;
	std::cin >> userNumber;

	std::vector<int> newVec;
	int currentSize = 0;

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != userNumber) {
			newVec.push_back(vec[i]);
			currentSize++;
		}
	}

	std::cout << "Your new array is: ";

	for (int i = 0; i < currentSize; i++) {
		std::cout << newVec[i] << " ";
	}
}