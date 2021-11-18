#include <iostream>
#include <map>
#include <string>

bool isCorrectInput(std::string& input) {
	for (int i = 0; i < input.length(); ++i) {
		if ((input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z')) return false;
	}

	return true;
}

bool isAnagram(std::string& first, std::string& second) {

	if (first.length() == second.length()) {
		std::map<char, int> fMap;
		std::map<char, int> sMap;

		for (int i = 0; i < first.length(); ++i) {
			if (fMap.find(first[i]) == fMap.end()) {
				fMap.emplace(first[i], 1);
			}
			else {
				std::map<char, int>::iterator it = fMap.find(first[i]);
				(it->second)++;
			}
		}

		for (int i = 0; i < second.length(); ++i) {
			if (sMap.find(second[i]) == sMap.end()) {
				sMap.emplace(second[i], 1);
			}
			else {
				std::map<char, int>::iterator it = sMap.find(second[i]);
				++(it->second);
			}
		}

		for (std::map<char, int>::iterator i = fMap.begin(), j = sMap.begin(); i != fMap.end(); ++i) {

			if (i->second != j->second) return false;

			++j;
		}

		return true;
	}
	else return false;
	
}

int main() {
	std::string first, second;

	std::cout << "Input your first data: ";
	std::getline(std::cin, first);

	while (!isCorrectInput(first)) {
		std::cout << "Wrong input, try again: ";
		std::getline(std::cin, first);
	}

	std::cout << "Input your second data: ";
	std::getline(std::cin, second);

	while (!isCorrectInput(second)) {
		std::cout << "Wrong input, try again: ";
		std::getline(std::cin, second);
	}

	std::cout << (isAnagram(first, second) ? "True!" : "False") << std::endl;
}