#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Worker {
protected:
	enum eCommandType {
		NONE,
		A,
		B,
		C
	};

private:
	eCommandType command = NONE;

public:
	
	void setCommand(const eCommandType& command) {

		this->command = command;
	}

	eCommandType getCommand() { return command; }
};

class Manager : public Worker {
private:
	int ID = 0;
	std::vector<Worker> group;

public:
	Manager() {}

	Manager(const int& ID);

	bool isAnyWorkerFree();

	void getCommandFromBoss(const int& inCommand);
};

Manager::Manager(const int& ID) {

	std::cout << "===============TEAM # " << ID << "======================" << std::endl;

	this->ID = ID;

	std::cout << "Input people's amount in this team: ";
	int amount;
	std::cin >> amount;

	group.resize(amount);

	system("cls");
}

void Manager::getCommandFromBoss(const int& inCommand) {

	std::srand(ID + inCommand);

	int subCommands = std::rand() % group.size() + 1;

	for (int i = 0; i < group.size() && subCommands > 0; ++i) {

		if (group[i].getCommand() != NONE) {

			int tempType = std::rand() % 3 + 1;

			switch (tempType)
			{
			case A:
				group[i].setCommand(A);
				break;

			case B:
				group[i].setCommand(B);
				break;

			case C:
				group[i].setCommand(C);
				break;
			}
		}		
	}
}

bool Manager::isAnyWorkerFree() {

	for (int i = 0; i < group.size(); ++i) {

		if (group[i].getCommand() == NONE) return true;
	}

	return false;
}

class BigBoss {
private:
	std::vector<Manager> team;
	bool isAnyFreeTeam = true;

public:
	BigBoss();

	void doCommand();

	bool isAnyFree() { return isAnyFreeTeam; }
};

BigBoss::BigBoss() {

	std::cout << "Input number of teams: ";
	int count;
	std::cin >> count;

	team.resize(count);

	for (int i = 0; i < team.size(); ++i) {

		team[i] = Manager(i + 1);
	}
}

void BigBoss::doCommand() {

	std::cout << "Input command: ";
	int command;
	std::cin >> command;

	for (int i = 0; i < team.size(); ++i) {

		if (team[i].isAnyWorkerFree()) {

			team[i].getCommandFromBoss(command);

			isAnyFreeTeam = true;

			system("cls");

			break;
		}	

		isAnyFreeTeam = false;
	}
}

int main() {

	BigBoss boss;

	do {

		boss.doCommand();

	} while (boss.isAnyFree());

	std::cout << "There is no free people for work!" << std::endl;

	std::cout << "==================GOODBYE!==================" << std::endl;
}