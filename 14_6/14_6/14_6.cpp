#include <iostream>
#include <vector>

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*���������� ������� ������ ��������� ������� �� �������, � ������ � ��������� ������� �� �������. 
	������ �������� ����� ������ �������������� � ������������ ��������� � ����� � � ������������ 
	������� � ���������, ������� ��� ����� ������� �����������.

	����, � ��� ���� 4-� ������������ ������ V �������������� � ������� �������, � ������� M �������� 
	4�4, �������������� � ���� ���������� �������. �� ������������� ����� ����� 4-� ������������ ������ R. 
	��� ���������� ����� ������ ������������ ��������� ������� V �� ������ ������� M. ������ ������� ��� 
	���� ����� ������� ��������������� ���������� ������� R, ������� �� � ������������ � ������� ������ �������.

	��� ������� ������, ������� M � ������ V �������� �� ����������������� �����.  �������� ������ R ���� 
	������� � ������� (std::cout). ��� ������ ��������� - ������ float. ���������� ����������� ���� 
	�������� � ������� ���������� ����� �� ��������� �������.*/

	std::vector<float> v(4);
	float m[4][4];
	std::vector<float> r(4);
	
	//������� �(l,m) �������� �� ������� �(m,n) = ������� �(l,n), ������ � ��� ����� 1 ������, ��� �������.

	std::cout << "Input your vector: " << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cin >> v[i];
	}

	std::cout << "Input your matrix 4x4: " << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> m[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			r[i] += v[j] * m[j][i];
		}
	}

	std::cout << "Result is: ";

	for (int i = 0; i < 4; i++) {
		std::cout << r[i] << ' ';
	}
}