#include <iostream>
#include <cmath>

#define PI 3.141592

enum eColors {
	NONE,
	RED,
	BLUE,
	GREEN
};

enum eCommands {
	CIRCLE = 1,
	SQUARE,
	TRIANGLE,
	RECTANGLE,
	EXIT
};

int getColor();

void showCoordinatOfRectangle(const double& edge, const double& midX, const double& midY, const double& secondEdge);

class Basic {

protected:
	double middleX = 0.0;
	double middleY = 0.0;
	int color = NONE;

public:
	
	Basic() {
		std::cout << "Input middle point coordinates (x, y): ";
		std::cin >> middleX >> middleY;

		color = getColor();
	}
};

class Circle : public Basic {

protected:
	double radius = 0.0;

public:

	Circle() {

		std::cout << "Input circle radius: ";
		std::cin >> radius;

		while (radius <= 0) {

			std::cout << "Wrong! Try again: ";
			std::cin >> radius;
		}

		std::cout << "Square = " << getSquare() << std::endl;

		showCoordinatOfRectangle(radius, middleX, middleY, radius);
	}

	double getSquare() { return PI * std::pow(radius, 2); }
};

class Triangle : public Basic {

protected:
	double edge = 0.0;

public:

	Triangle() {

		std::cout << "Input triangle edge: ";
		std::cin >> edge;

		while (edge <= 0) {

			std::cout << "Wrong! Try again: ";
			std::cin >> edge;
		}

		std::cout << "Square = " << getSquare() << std::endl;

		double height = (edge * std::sqrt(3)) / 2;

		showCoordinatOfRectangle(edge, middleX, middleY, height);

	}

	double getSquare() { return (std::pow(edge, 2) * std::pow(3, 1/2)) / 4; }
};

class Square : public Basic {

protected:
	double edge = 0.0;

public:

	Square() {

		std::cout << "Input square edge: ";
		std::cin >> edge;

		while (edge <= 0) {

			std::cout << "Wrong! Try again: ";
			std::cin >> edge;
		}

		std::cout << "Square = " << getSquare() << std::endl;

		showCoordinatOfRectangle(edge, middleX, middleY, edge);
	}

	double getSquare() { return std::pow(edge, 2); }
};

class Rectangle : public Basic {

protected:
	double weight = 0.0;
	double height = 0.0;

public:

	Rectangle() {

		std::cout << "Input rectangle weight and height: ";
		std::cin >> weight >> height;

		while (weight <= 0 || height <= 0) {

			std::cout << "Wrong! Try again: ";
			std::cin >> weight >> height;
		}

		std::cout << "Square = " << getSquare() << std::endl;

		showCoordinatOfRectangle(weight, middleX, middleY, height);
	}

	double getSquare() { return weight * height; }
};

void showCommands() {
	
	std::cout << CIRCLE << ". To create circle and found it's square and describing rectangle;" << std::endl;
	std::cout << SQUARE << ". To create square and found it's square and describing rectangle;" << std::endl;
	std::cout << TRIANGLE << ". To create triangle and found it's square and describing rectangle;" << std::endl;
	std::cout << RECTANGLE << ". To create rectangle and found it's square and describing rectangle;" << std::endl;
	std::cout << EXIT << ". Exit programm." << std::endl;
	
	std::cout << "Input number of command you wish to do: ";
}

int main() {

	int userInput;

	std::cout << "=================WELCOME!===============" << std::endl;

	do {

		showCommands();
		std::cin >> userInput;

		switch (userInput)
		{
		case CIRCLE:
			{Circle* temp = new Circle;
			system("cls");
			delete temp;
			temp = nullptr;
			break; }

		case SQUARE:
			{Square* temp = new Square;
			system("cls");
			delete temp;
			temp = nullptr;
			break; }

		case TRIANGLE:
			{Triangle* temp = new Triangle;
			system("cls");
			delete temp;
			temp = nullptr;
			break; }

		case RECTANGLE:
			{Rectangle* temp = new Rectangle;
			system("cls");
			delete temp;
			temp = nullptr;
			break; }

		case EXIT:
			system("cls");
			break;

		default:
			system("cls");
			std::cout << "Wrong input! Try again!" << std::endl;
			break;
		}

	} while (userInput != EXIT);

	std::cout << "=================GOODBYE!===================" << std::endl;
}

int getColor() {

	std::cout << RED << ". Red color;" << std::endl;
	std::cout << BLUE << ". Blue color;" << std::endl;
	std::cout << GREEN << ". Green color." << std::endl;

	int answer;

	std::cout << "Type your colour: ";
	std::cin >> answer;

	while (answer < NONE || answer > GREEN) {

		std::cout << "Wrong input! Try again: ";
		std::cin >> answer;
	}

	system("cls");

	return answer;
}

void showCoordinatOfRectangle(const double& edge, const double& midX, const double& midY, const double& secondEdge) {

	std::cout << "LEFT TOP {" << midX - edge / 2 << ";" << midY + secondEdge / 2 << "}" << std::endl;
	std::cout << "RIGHT TOP {" << midX + edge / 2 << ";" << midY + secondEdge / 2 << "}" << std::endl;
	std::cout << "LEFT BOTTOM {" << midX - edge / 2 << ";" << midY - secondEdge / 2 << "}" << std::endl;
	std::cout << "RIGHT BOTTOM {" << midX + edge / 2 << ";" << midY - secondEdge / 2 << "}" << std::endl;
}