#include <iostream>

void evenNumbers(long long n, int& ans) {
	if ((n / 10 != 0) || (n / 10 == 0 && n % 10 != 0)) {
		if ((n % 10) % 2 == 0) {
			ans++;
		}
		evenNumbers(n / 10, ans);
	}
}

int main() {
	long long n;
	std::cout << "Input your big number: ";
	std::cin >> n;

	int ans = 0;

	evenNumbers(n, ans);

	std::cout << "Ans = " << ans << std::endl;
}