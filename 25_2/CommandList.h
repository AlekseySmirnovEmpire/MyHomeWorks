#pragma once
#include <iostream>

enum eCommandNumber
{
	SUM = 1,
	SAVE,
	LOAD,
	INPUT,
	DISPLAY,
	EXIT
};

inline void showCommands() {

	std::cout << SUM << ". Sum and show 8 numbers from RAM;" << std::endl;
	std::cout << SAVE << ". Save numbers in file;" << std::endl;
	std::cout << LOAD << ". Load numbers from file;" << std::endl;
	std::cout << INPUT << ". Input 8 numbers from keybord;" << std::endl;
	std::cout << DISPLAY << ". Show numbers on display;" << std::endl;
	std::cout << EXIT << ". Exit." << std::endl;

	std::cout << "Input number of command you want to do: ";

}

int read(int& i);

void write(int& i, int& temp);

void show();

void input();

void show();

void sum();

void save();

void load();
