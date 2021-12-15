#include <iostream>

enum eWorkType {
	NONE,
	A,
	B,
	C
};

class People {

protected:
	int workType = NONE;
	bool isWorking = false;

public:
	void setType(const int& workType) { this->workType = workType; }

	void setWorking() { isWorking = true; }

	bool getWorkingStatus() { return isWorking; }
};

class Team {
protected:
	int managerID = 0;
	int people = 0;
	People* count = nullptr;
	
public:
	Team(const int& managerID, const int& people) {

		this->managerID = managerID;
		this->people = people;

		this->count = new People[this->people];
	}

	Team() {};

	~Team() {

		delete[] count;
		count = nullptr;
	}

	bool setWork(const int& work) {

		std::srand(work + this->managerID);

		int subWorks = std::rand() % this->people + 1;

		bool workIsDone = false;

		for (int i = 0; i < this->people && subWorks > 0; ++i) {

			if (!count[i].getWorkingStatus()) {

				int type = std::rand() % 3 + 1;

				switch (type)
				{
				case A:
					this->count[i].setType(A);
					break;

				case B:
					this->count[i].setType(B);
					break;

				case C:
					this->count[i].setType(C);
					break;
				}

				count[i].setWorking();

				--subWorks;

				workIsDone = true;
			}					
		}

		return workIsDone;
	}

	bool isAnyHumanIsNotAtWork() {

		for (int i = 0; i < people; ++i) {

			if (count[i].getWorkingStatus()) return true;
		}

		return false;
	}

};

class Company {
private:
	Team* teams = nullptr;
	bool isFullInWork = false;
	int teamsCount = 0;

public:
	Company(const int& teamsCount);

	~Company();

	void doWork();

	bool isFull() {

		bool full = false;

		for (int i = 0; i < teamsCount; ++i) {

			if (teams[i].isAnyHumanIsNotAtWork()) return false;
		}

		return true;
	}
};

Company::Company(const int& teamsCount) {

	this->teamsCount = teamsCount;

	teams = new Team[this->teamsCount];

	for (int i = 0; i < this->teamsCount; ++i) {

		std::cout << "================Team #" << i + 1 << "===================" << std::endl;

		std::cout << "Input number of people in team: ";

		int people;

		std::cin >> people;

		teams[i] = Team(i + 1, people);

		system("cls");

	}
}

Company::~Company() {

	delete[] teams;
	teams = nullptr;
}

void Company::doWork() {

	std::cout << "Input number of works: ";
	
	int works;

	std::cin >> works;

	for (int i = 0; i < teamsCount; ++i) {

		if (teams[i].setWork(works)) break;
	}

	system("cls");
}

void createCompany(Company* boss) {

	std::cout << "Input number of teams: ";
	
	int count;

	std::cin >> count;

	*boss = Company(count);
}


int main() {

	Company* boss = nullptr;

	createCompany(boss);

	while (!boss->isFull()) {

		boss->doWork();

		system("cls");
	}

	delete boss;
	boss = nullptr;

	std::cout << "All people is in work now!" << std::endl;
}