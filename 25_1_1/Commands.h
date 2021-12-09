#pragma once
#include <iostream>

enum {
	SCALPEL = 1,
	HEMOSTAT,
	TWEEZERS,
	SUTURE
};

struct Point
{
	double pointX = 0;
	double pointY = 0;
};

void showCommandList() {
	std::cout << "Chose command to do:" << std::endl;
	std::cout << SCALPEL << ". Make scalpel cut from one point to another;" << std::endl;
	std::cout << HEMOSTAT << ". Make hemostat in one point;" << std::endl;
	std::cout << TWEEZERS << ". Make tweezers in one point;" << std::endl;
	std::cout << SUTURE << ". Make suture between two points." << std::endl;

	std::cout << "Input number of your command: ";
}

void scalpelMake(Point* point, bool isInitAction = false) {

	if (!isInitAction) {

		Point* temp = new Point[2];

		std::cout << "Input first point X Y: ";
		std::cin >> temp[0].pointX >> temp[0].pointY;

		std::cout << "Input second point X Y: ";
		std::cin >> temp[1].pointX >> temp[1].pointY;

		if (temp[0].pointX == point[0].pointX && temp[0].pointY == point[0].pointY &&
			temp[1].pointX == point[1].pointX && temp[1].pointY == point[1].pointY) {

			std::cout << "It's your start cut! Try again!" << std::endl;
		}
		else {

			std::cout << "You make scalpel cut from [" << temp[0].pointX << ',' << temp[0].pointY << "] to [" << temp[1].pointX << ',' << temp[1].pointY << "]." << std::endl;
		}

		delete[] temp;
		temp = nullptr;

	}
	else {

		std::cout << "Input first point X Y: ";
		std::cin >> point[0].pointX >> point[0].pointY;

		std::cout << "Input second point X Y: ";
		std::cin >> point[1].pointX >> point[1].pointY;

		std::cout << "You make scalpel cut from [" << point[0].pointX << ',' << point[0].pointY << "] to [" << point[1].pointX << ',' << point[1].pointY << "]." << std::endl;

	}
}

void hemostatMake() {

	Point* point = new Point;

	std::cout << "Input point X Y: ";
	std::cin >> point->pointX >> point->pointY;

	std::cout << "You make hemostat in [" << point->pointX << ',' << point->pointY << "]." << std::endl;

	delete point;
	point = nullptr;

}

void tweezersMake() {

	Point* point = new Point;

	std::cout << "Input point X Y: ";
	std::cin >> point->pointX >> point->pointY;

	std::cout << "You make tweezers in [" << point->pointX << ',' << point->pointY << "]." << std::endl;

	delete point;
	point = nullptr;

}

void sutureMake(Point* start, bool* isOver) {

	Point* point = new Point[2];

	std::cout << "Input first point X Y: ";
	std::cin >> point[0].pointX >> point[0].pointY;

	std::cout << "Input second point X Y: ";
	std::cin >> point[1].pointX >> point[1].pointY;

	std::cout << "You make suture from [" << point[0].pointX << ',' << point[0].pointY << "] to [" << point[1].pointX << ',' << point[1].pointY << "]." << std::endl;

	*isOver = point[0].pointX == start[0].pointX && point[0].pointY == start[0].pointY &&
		point[1].pointX == start[1].pointX && point[1].pointY == start[1].pointY;

	delete[] point;
	point = nullptr;

}