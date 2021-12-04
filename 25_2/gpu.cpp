#include "CommandList.h"
#include <iostream>

void show() {

	for (int i = 0; i < 8; i++) {

		std::cout << read(i) << " ";

	}

	std::cout << std::endl;

}