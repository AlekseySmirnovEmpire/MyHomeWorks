#include <iostream>
#include <vector>


int main() {
	setlocale(LC_ALL, ".UTF8");

	/*� ���������� �������� �����. ����� ������������ ������ -1 -- ���������� �������� 
	�� ����� ����� �� ����������� ����� ����� ��������. ����� ������������ ������ -2 -- 
	��������� ��������� ������.
	������:
	����: 7 5 3 1 2 4 6 -1
	�����: 5 (� ��������������� ���� ������ �������� ���: {1,2,3,4,5,6,7})
	����: 1 1 1 -1
	�����: 2 (� ��������������� ���� ������ �������� ���: {1,1,1,1,2,3,4,5,6,7})
	���� -2
	���������� ���������*/

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