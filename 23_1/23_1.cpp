#include <iostream>

#define DAY1 "Monday"
#define DAY2 "Tuesday"
#define DAY3 "Wednesday"
#define DAY4 "Thursday"
#define DAY5 "Friday"
#define DAY6 "Saturday"
#define DAY7 "Sunday"

#define DAY_OF_THE_WEEK(a) DAY ## a

int main() {
	
	std::cout << "Input your number of the day: " << std::endl;

	int n;

	std::cin >> n;

	while (n < 1 || n > 7) {

		std::cout << "Wrong input, try again: ";
		
		std::cin >> n;

	}

	if (n == 1) std::cout << DAY_OF_THE_WEEK(1) << std::endl;
	else if (n == 2) std::cout << DAY_OF_THE_WEEK(2) << std::endl;
	else if (n == 3) std::cout << DAY_OF_THE_WEEK(3) << std::endl;
	else if (n == 4) std::cout << DAY_OF_THE_WEEK(4) << std::endl;
	else if (n == 5) std::cout << DAY_OF_THE_WEEK(5) << std::endl;
	else if (n == 6) std::cout << DAY_OF_THE_WEEK(6) << std::endl;
	else std::cout << DAY_OF_THE_WEEK(7) << std::endl;
	
}