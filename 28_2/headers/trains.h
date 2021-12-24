#pragma once

#include <iostream>
#include <vector>

class Train {
	
private:
	int speed = 0;
	std::string name = "";

public:
	Train();

	int getSpeed() { return this->speed; }

	std::string getName() { return this->name; }
};

void createTrain(std::vector<Train>& trains);