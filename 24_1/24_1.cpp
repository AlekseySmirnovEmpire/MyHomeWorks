#include <iostream>
#include <ctime>
#include <string>
#include <vector>

enum eMenuCommands {
	BEGIN = 1,
	STATUS,
	END,
	EXIT
};

struct Works
{
	std::string s_name = "";
	int s_time = 0;
	long s_startTime = 0;
};

std::string transformTime(const int& time) {
	std::string output = "00:00";

	int curTime = time;

	while (curTime >= 360)
	{
		curTime -= 360;
		
		if (output[1] == '9') {
			output[1] = '0';
			output[0] = (char)((int)(output[0]) + 1);
		}
		else {
			output[1] = (char)((int)(output[1]) + 1);
		}
	}

	while (curTime >= 60) {
		curTime -= 60;

		if (output[4] == '9') {
			output[4] = '0';
			output[3] = (char)((int)(output[3]) + 1);
		}
		else {
			output[4] = (char)((int)(output[4]) + 1);
		}
	}

	output += ":" + std::to_string(curTime);

	return output;
}

void showMenu() {
	std::cout << BEGIN << ". Begin new work;" << std::endl;
	std::cout << STATUS << ". Show status of all works u've done;" << std::endl;
	std::cout << END << ". End work;" << std::endl;
	std::cout << EXIT << ". Exit programm." << std::endl;

	std::cout << "Input number of command you wish to do: ";
}

void beginCommand(std::vector<Works>& input) {
	Works* temp = new Works;

	std::cout << "Input name of your work: ";
	std::string name;
	std::getline(std::cin, name);

	temp->s_name = name;

	if (input.size() != 0 && input[input.size() - 1].s_time == 0) {

		input[input.size() - 1].s_time = (int)(std::time(nullptr) - input[input.size() - 1].s_startTime);

	}
	
	temp->s_startTime = std::time(nullptr);

	temp->s_time = 0;

	input.push_back(*temp);

	delete temp;
	temp = nullptr;
}

void endCommand(std::vector<Works>& input) {
	if (input.size() != 0 && input[input.size() - 1].s_time == 0) {

		input[input.size() - 1].s_time = (int)(std::time(nullptr) - input[input.size() - 1].s_startTime);

		std::cout << "\"" << input[input.size() - 1].s_name << "\" now ended!" << std::endl;
	}
	else {
		std::cout << "No commands to end!" << std::endl;
	}
}

void statusCommand(std::vector<Works>& input) {

	if (input.size() != 0) {
		for (int i = 0; i < input.size(); ++i) {
			if (input[i].s_time == 0) {
				std::cout << "\"" << input[i].s_name << "\" in PROGRESS!" << std::endl;
			}
			else {
				std::cout << "\"" << input[i].s_name << "\" finished in " << transformTime(input[i].s_time) << '.' << std::endl;
			}
		}
	}
	else {
		std::cout << "No commands have been done!" << std::endl;
	}
}

int main() {

	/*Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.

	Пользователь взаимодействует с программой с помощью команд:

	Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести
	название задачи, над которой он планирует сейчас работать. Если уже была начата какая-то другая задача,
	предыдущая должна быть автоматически завершена и начата новая.
	Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего
	не делает.
	Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них
	потрачено. Также выводится название текущей выполняемой задачи, если таковая имеется.
	Команда exit выходит из программы. */


	int userInput;

	std::vector<Works> works;

	do {
		showMenu();
		std::cin >> userInput;
		std::cin.ignore();

		switch (userInput)
		{
		case BEGIN:
			beginCommand(works);

			break;

		case STATUS:
			system("cls");

			statusCommand(works);

			break;

		case END:
			endCommand(works);

			break;

		case EXIT:
			break;

		default:
			std::cout << "Wrong input! Try again!" << std::endl;
			break;
		}

		std::cout << "========================" << std::endl;

	} while (userInput != EXIT);

	std::cout << "==============GOODBYE!==============" << std::endl;
}