#include <iostream>
#include <ctime>
#include <iomanip>

int main() {

	std::time_t start = std::time(nullptr);
	std::tm expected = *std::localtime(&start);

	std::cout << "Input time in format MM:SS : ";

	std::cin >> std::get_time(&expected, "%M:%S");

	int* leftSeconds = new int;

	*leftSeconds = expected.tm_min * 60 + expected.tm_sec;

	std::time_t current = std::time(nullptr);
	start = current;

	int* totalSeconds = new int;
	*totalSeconds = *leftSeconds;

	while (current != start + *totalSeconds) {
		
		current = std::time(nullptr);

		if (current == start + *totalSeconds - *leftSeconds) {

			if (*leftSeconds / 60 < 10) std::cout << '0';
			std::cout << *leftSeconds / 60 << ':';

			if (*leftSeconds % 60 < 10) std::cout << '0';
			std::cout << *leftSeconds % 60 << std::endl;

			--* leftSeconds;
		}
	}

	std::cout << "DING! DING! DING!" << std::endl;

	delete leftSeconds;
	leftSeconds = nullptr;

	delete totalSeconds;
	totalSeconds = nullptr;
}