#include <iostream>
#include <string>
#include <sstream>

int smartPanel = 0;

enum smartHouse {
	ELEC_HOUSE = 1 << 0,
	ELEC_SOCKETS = 1 << 1,
	LIGHT_HOUSE = 1 << 2,
	LIGHT_OUT = 1 << 3,
	HEATING_HOUSE = 1 << 4,
	HEATING_WATER = 1 << 5,
	CONDITIONER = 1 << 6
};

bool isMovement(std::string input) {
	return input == "yes";
}

bool isLightOn(std::string input) {
	return input == "on";
}

void checkTempIn(int temp) {
	if (temp < 22 && !(smartPanel & HEATING_HOUSE)) {
		smartPanel |= HEATING_HOUSE;
		std::cout << "Heating of the house is ON" << std::endl;
	}
	else if (temp >= 25 && (smartPanel & HEATING_HOUSE)) {
		smartPanel &= ~HEATING_HOUSE;
		std::cout << "Heating of the house is OFF" << std::endl;
	}
}

void checkConditioner(int temp) {
	if (temp >= 30 && !(smartPanel & CONDITIONER)) {
		smartPanel |= CONDITIONER;
		std::cout << "Conditioner is ON" << std::endl;
	}
	else if (temp <= 25 && (smartPanel & CONDITIONER)) {
		smartPanel &= ~CONDITIONER;
		std::cout << "Conditioner if OFF" << std::endl;
	}
}

void checkWater(int temp) {
	if (temp < 0 && !(smartPanel & HEATING_WATER)) {
		smartPanel |= HEATING_WATER;
		std::cout << "Heating water tubes is ON" << std::endl;
	}
	else if (temp > 5 && (smartPanel & HEATING_WATER)) {
		smartPanel &= ~HEATING_WATER;
		std::cout << "Heating water tubes is OFF" << std::endl;
	}
}

void checkLightOut(int time, bool movement) {
	if (((time >= 16 && time <= 24) || (time >= 0 && time <= 5) || (time - 24 >= 16 && time - 24 <= 24)
			|| (time - 24 >= 0 && time - 24 <= 5)) && movement && !(smartPanel & LIGHT_OUT)) {
		smartPanel |= LIGHT_OUT;
		std::cout << "Light in the garden is ON" << std::endl;
	}
	else if ((!((time >= 16 && time <= 24) || (time >= 0 && time <= 5) || (time - 24 >= 16 && time - 24 <= 24)
			|| (time - 24 >= 0 && time - 24 <= 5)) || !movement) && (smartPanel & LIGHT_OUT)) {
		smartPanel &= ~LIGHT_OUT;
		std::cout << "Light in the garden is OFF" << std::endl;
	}
}

void checkLightIn(bool light) {
	if (light && !(smartPanel & LIGHT_HOUSE)) {
		smartPanel |= LIGHT_HOUSE;
		std::cout << "Light in the house is ON" << std::endl;
	}
	else if (!light && (smartPanel & LIGHT_HOUSE)) {
		smartPanel &= ~LIGHT_HOUSE;
		std::cout << "Light in the house is OFF" << std::endl;
	}
}

void lampTemp(int time) {
	int maxTemp = 5000;
	int minTemp = 2700;
	if ((time < 16 && time >= 0) || (time - 24 < 16 && time - 24 >= 0)) {
		std::cout << std::to_string(maxTemp) << " K" << std::endl;
	}
	else if ((time >= 20 && time < 24) || (time - 24 >= 20 && time - 24 < 24)) {
		std::cout << std::to_string(minTemp) << " K" << std::endl;
	}
	else {
		std::cout << std::to_string(maxTemp - (((maxTemp - minTemp) / (20 - 16)) * (time - 16))) << " K" << std::endl;
	}
}

void currentTime(int time) {
	std::cout << "-------Current time is: ";
	if (time < 10) {
		std::cout << "0" << std::to_string(time);
	}
	else if (time >= 24) {
		if (time - 24 >= 10) {
			std::cout << std::to_string(time - 24);
		}
		else {
			std::cout << "0" << std::to_string(time - 24);
		}
	}
	else {
		std::cout << std::to_string(time);
	}
	std::cout << ":00-------" << std::endl;
}

int main() {
	/*Надо разработать упрощённую модель умного дома для дачи. Есть несколько датчиков: 
	датчик температуры снаружи, датчик температуры внутри дома. В доме расположен электронный 
	“умный” щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых 
	устройств или групп устройств. Первый автомат - это отключение и включение питания всего 
	дома, второй - основные розетки дома, третий - свет внутри дома, четвёртый - наружный 
	свет в саду, пятый - отопление в помещении, шестой - отопление водопровода идущего 
	из скважины с насосом, седьмой - кондиционер в помещении.
	Есть несколько условий по включению/отключению техники в доме и вне его.
	Как только температура снаружи падает ниже 0, надо включить систему обогрева водопровода 
	и отключить её, если температура снаружи поднялась выше 5 градусов.
	Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, 
	то необходимо включить садовое освещение. Если движения нет или время не вечернее - света 
	снаружи быть не должно.
	При условии, что температура в помещении упала ниже 22 градусов, должно включится отопление. 
	Как только температура поднимается выше или равно 25-и градусам, отопление автоматически 
	отключается.
	Если температура в помещении поднялась до 30 градусов, включается кондиционер. 
	Как только температура становится 25 градусов - кондиционер отключается.
	Всё освещение в доме также “умное” и поддерживает настройку цветовой температуры для 
	комфортного нахождения. Каждый день начиная с 16:00 и до 20:00, температура цвета должна 
	плавно изменяться с 5000K до 2700К. Разумеется, это изменение должно происходить в случае, 
	если свет сейчас включен. В 0:00 температура сбрасывается до 5000К.
	Все события по отключению и включению устройств должны выводится в консоль явным образом. 
	Если устройство не изменило своего состояния (осталось включенным или выключенным) события 
	генерироваться не должно! Если свет в доме включен, должна отображаться текущая цветовая 
	температура.
	Программа выполняется следующим образом. Каждый час пользователь сообщает состояние всех 
	основных датчиков и света: температура снаружи, температура внутри, есть ли движение снаружи, 
	включен ли свет в доме. Данные параметры вводятся разом в одну строку, через пробел, а потом
	парсятся в переменные из строкового буфера stringstream. Информация о движении выводится в
	формате yes/no. Включение и отключение света происходит с помощью on/off. Стартовое время 
	для симуляции умного дома - это 0:00. Требуется осуществить симуляцию на протяжении двух дней.*/

	const int time = 48;
	std::string userInput;
	int tempIn, tempOut;
	bool movement, lightOn;

	for (int i = 0; i < time; i++) {
		currentTime(i);

		std::cout << "Input current temperature outside, inside, is there any motion outside and is light on/off inside the\nhouse (temp1 temp2 yes/no on/off): ";
		std::getline(std::cin, userInput);

		std::stringstream input;

		input << userInput;

		std::string move;
		std::string light;

		input >> tempOut >> tempIn >> move >> light;

		movement = isMovement(move);
		lightOn = isLightOn(light);

		checkTempIn(tempIn);
		checkConditioner(tempIn);
		checkWater(tempOut);
		checkLightOut(i, movement);
		checkLightIn(lightOn);
		if (lightOn) {
			lampTemp(i);
		}
	}
}