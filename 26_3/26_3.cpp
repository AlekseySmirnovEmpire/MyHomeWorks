#include <iostream>
#include <vector>

enum eCommands
{
	MOVE = 1,
	RESIZE,
	DISPLAY,
	CLOSE
};

class Window
{
private:
	int m_x;
	int m_y;
	int m_weight;
	int m_height;

	bool isCorrectInput(int x, int y) {

		return (m_x + x >= 0) && (m_y + y >= 0) && (m_y + y + m_height < 50) && (m_x + x + m_weight < 80);
	}

	void showParametrs(bool isCoordinates) {

		if (isCoordinates) {

			std::cout << "Left angle X: " << m_x << std::endl;
			std::cout << "Left angle Y: " << m_y << std::endl;
		}
		else {

			std::cout << "Weight: " << m_weight << std::endl;
			std::cout << "Height: " << m_height << std::endl;
		}	
		
	}

public:

	Window() {
		std::cout << "Input coordinates of left angle (x y): ";
		std::cin >> m_x >> m_y;

		std::cout << "Input weight: ";
		std::cin >> m_weight;

		std::cout << "Input height: ";
		std::cin >> m_height;
	}

	void move() {
		std::cout << "Input mooving vector {x,y}: ";
		int temp_x, temp_y;
		std::cin >> temp_x >> temp_y;

		while (!isCorrectInput(temp_x, temp_y)) {

			std::cout << "Wrong input! Try again: ";
			std::cin >> temp_x >> temp_y;
		}

		m_x += temp_x;
		m_y += temp_y;

		showParametrs(true);
	}

	void resize() {

		std::cout << "Input new weight: ";
		int temp_weight;
		std::cin >> temp_weight;

		std::cout << "Input new height: ";
		int temp_height;
		std::cin >> temp_height;

		while (!(m_x + temp_weight < 80 && m_y + temp_height < 50 && temp_height > 0 && temp_weight > 0)) {

			std::cout << "Wrong input! Try again!" << std::endl;
			
			std::cout << "Input new weight: ";
			std::cin >> temp_weight;

			std::cout << "Input new height: ";
			std::cin >> temp_height;
		}

		m_height = temp_height;
		m_weight = temp_weight;

		showParametrs(false);
	}

	void display() {

		for (int i = 0; i < 80; ++i) {

			for (int j = 0; j < 50; ++j) {

				if ((i >= m_x && i < m_x + m_weight) && (j >= m_y && j < m_y + m_height)) {

					std::cout << "1";
				}
				else std::cout << "0";
			}

			std::cout << std::endl;
		}
	}
};

void showCommands() {

	std::cout << MOVE << ". Move window on screen;" << std::endl;
	std::cout << RESIZE << ". Resize window;" << std::endl;
	std::cout << DISPLAY << ". Show on display window;" << std::endl;
	std::cout << CLOSE << ". Close the programm;" << std::endl;

	std::cout << "Input number of command you wish to do: " << std::endl;
}

int main() {
	
	int userInput;

	Window window;

	do {

		showCommands();
		std::cin >> userInput;

		switch (userInput)
		{
		case MOVE:
			system("cls");
			window.move();
			break;

		case RESIZE:
			system("cls");
			window.resize();
			break;

		case DISPLAY:
			system("cls");
			window.display();
			break;

		case CLOSE:
			system("cls");
			break;

		default:
			system("cls");
			std::cout << "Uknown command! Try again!" << std::endl;
			break;
		}

		std::cout << "---------------------------------" << std::endl;

	} while (userInput != CLOSE);

	std::cout << "=================GOODBYE!==================" << std::endl;
}