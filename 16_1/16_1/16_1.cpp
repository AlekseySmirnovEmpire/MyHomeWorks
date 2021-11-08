#include <iostream>
#include <stdio.h>

bool compare(double value, double reference, double dif) {
	return (reference >= value - dif) && (reference <= value + dif);
}

int main() {

	/*Надо реализовать цифровой спидометр автомобиля. Сама модель автомобиля, 
	которую нужно будет воссоздать весьма проста. Начальная скорость - 0 км/ч. 
	Пользователь вводит в стандартный ввод разницу (дельту) в скорости и 
	результирующая скорость показывается на спидометре в стандартный вывод. 
	Так происходит до той поры, пока машина снова не остановится, т.е. пока 
	скорость не станет меньше или равна нулю (сравнение должно происходить с 
	дельтой в 0.01). Диапазон возможных значений скорости машины от 0 до 150 км/ч. 
	Сам показатель спидометра, вместе с единицами измерения, требуется записывать 
	в отдельную строку-буфер, которая потом и будет показываться на экране. 
	Точность отображения скорость до 0.1 км/ч.*/

	char output[50];

	double speed = 0;
	double input;
	const double EPS = 0.01;

	do {
		std::cout << "Input your dif of speed: ";
		std::cin >> input;

		speed += input;

		if (speed > 150 + EPS) {
			speed = 150;
		}
		else if (compare(speed, 0, EPS) || speed < 0) {
			speed = 0;
		}

		std::sprintf(output, "Speed: %.1f km/h\n", speed);

		std::cout << output << std::endl;

	} while (!compare(speed, 0, EPS));

}