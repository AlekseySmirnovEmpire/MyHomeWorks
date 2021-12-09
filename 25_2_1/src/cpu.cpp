#include "CommandList.h"
#include <iostream>

void sum() {

	int* temp = new int;
	*temp = 0;

	for (int i = 0; i < 8; ++i) {

		*temp += read(i);

	}

	std::cout << "Sum is: " << *temp << std::endl;

	delete temp;
	temp = nullptr;
}