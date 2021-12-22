#pragma once

#include <iostream>
#include <string>
#include <map>

class Sportsman {

private:
	std::string name = "";
	double speed = 0;

public:
	Sportsman();

	std::string getName() { return this->name; }
	
	double getSpeed() { return this->speed; }
};

void startSwim(Sportsman& sportsman, std::map<int, std::string>& score);
void showScore(std::map<int, std::string>& score);
