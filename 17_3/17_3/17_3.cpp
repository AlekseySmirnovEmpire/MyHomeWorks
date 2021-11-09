#include <iostream>

bool isInsert(char* a,char* b) {

	bool match = false;
	for (; *a != '\0'; a++) {
		for (; *b != '\0'; b++) {
			if (*a == *b) match = true;
			else {
				match = false;
				break;
			}
		}
	}
	return match;
}

int main() {
	char a[] = "Hello world";
	char b[] = "wor";
	char c[] = "banana";

	std::cout << isInsert(a, b) << ' ' << isInsert(a, c) << std::endl;
}