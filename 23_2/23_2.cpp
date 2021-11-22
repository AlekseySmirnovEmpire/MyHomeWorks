#include <iostream>

#define CHECK_TRAIN(n, i)\
if ((n) > 20) std::cout << "Van #" << i << " is FULL!" << std::endl;\
else std::cout << "Amount of people in van #" << i + 1 << " is normal." << std::endl;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

int main() {

	int people[10];

	FOR(i, 0, 10) {
		std::cout << "Input amout of people in van #" << i + 1 << ": ";
		std::cin >> people[i];
	}

	FOR(i, 0, 10) {
		CHECK_TRAIN(people[i], i)
	}
}