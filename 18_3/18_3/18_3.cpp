#include <iostream>

int rabbitJump(int steps, int jump, int temp = 0) {
	if (steps < 0) return 0;
	if (steps == 0) return 1;

	for (int i = jump; i > 0; i--) {
		temp += rabbitJump(steps - i, jump);
	}
	return temp;
}

int main() {
	int ladder;
	std::cout << "Input number of steps on ladder: ";
	std::cin >> ladder;

	int jumpHeight;
	std::cout << "Input number of steps that rabbit can jump over: ";
	std::cin >> jumpHeight;

	std::cout << "There're " << rabbitJump(ladder, jumpHeight) << " combinations." << std::endl;
}