#include <iostream>
#include <vector>
#include <cmath>

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*��� ����� ������ ����� �����, ��������������� �� �����������. 
	���������� ������� ��� �� ����� ��������������� � ������� ����������� 
	������ �����.
	������:
	������ {-100,-50, -5, 1, 10, 15}
	�����: 1, -5, 10, 15, -50, -100
	������� �� ���������: �������������� ������� �������� ������, 
	����� ��� ��������� ��� ����� ������ ��������*/

	std::vector<int> vec = { -100, -50, -5, 1, 10, 15 };

	for (int i = vec.size() - 1; i >= 0; i--) {
		int ind = 0;
		for (int j = 0; j <= i; j++) {
			if (std::abs(vec[j]) > std::abs(vec[ind])) ind = j;
		}
		int temp = vec[i];
		vec[i] = vec[ind];
		vec[ind] = temp;
	}


	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << ' ';
	}
}