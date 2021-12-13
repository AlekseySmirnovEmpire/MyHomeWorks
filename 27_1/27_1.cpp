#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Branch
{
private:
	std::string name = "none";
	int middleBranchesCount = 0;
	std::vector<Branch> middleBranch;

public:

	Branch(const std::string& name, bool isBigBranch = true) {

		if (isBigBranch) {

			middleBranchesCount = std::rand() % 2 + 2;

			this->name = name;

			for (int i = 0; i < middleBranchesCount; ++i) {

				std::cout << "Input elf name or \"none\": ";
				std::string tempName;
				std::getline(std::cin, tempName);

				Branch* temp = new Branch(tempName, false);

				middleBranch.push_back(*temp);

				delete temp;
				temp = nullptr;
			}
		}
		else {

			this->name = name;
		}
	}

	bool isElfOnMiddle(const std::string& inName) {

		for (int i = 0; i < middleBranchesCount; ++i) {

			if (middleBranch[i].name == inName) return true;
		}

		return false;
	}

	std::string getName() { return name; }
	int getCounter() { return middleBranchesCount; }

	Branch& getMiddle(const int& index) { return middleBranch[index]; }
};

class Forest 
{
private:
	std::vector<Branch> bigBranch;

public:
	Forest(const std::string& name) {

		int bigBranchesCount = std::rand() % 3 + 3;

		for (int i = 0; i < bigBranchesCount; ++i) {

			Branch* temp = new Branch(name);

			bigBranch.push_back(*temp);
			
			delete temp;
			temp = nullptr;
		}
	}

	int searchElf(const std::string& name, bool& isFound) {

		for (int i = 0; i < bigBranch.size(); ++i) {

			if (bigBranch[i].getName() == name || (bigBranch[i].getCounter() > 0 && bigBranch[i].isElfOnMiddle(name))) {

				isFound = true;
				return i;
			}
		}

		return 0;
	}

	int neighbourCount(const int& index) {

		int output = 0;
		
		if (bigBranch[index].getName() != "none") {

			++output;
		}
		if (bigBranch[index].getCounter() > 0) {

			for (int i = 0; i < bigBranch[index].getCounter(); ++i) {

				if (bigBranch[index].getMiddle(i).getName() != "none") ++output;
			}
		}

		return output;
	}

};

void createForest(const int& count, Forest* trees) {

	for (int i = 0; i < count; ++i) {

		std::string name;
		
		std::cout << "Input elf name or \"none\": ";
		std::getline(std::cin, name);

		trees[i] = Forest(name);

		system("cls");
	}
}

void searchForElf(const int& count, Forest* trees) {

	std::cout << "Input name of elf you wanted to find: ";

	std::string name;

	std::getline(std::cin, name);

	while (name == "none") {

		std::cout << "Wrong input! Try again: ";
		std::getline(std::cin, name);
	}

	bool isFound = false;

	for (int i = 0; i < count; ++i) {

		int temp = trees[i].searchElf(name, isFound);

		if (temp != 0) {

			isFound = true;

			std::cout << name << " have " << trees[i].neighbourCount(temp) << " neigbours!" << std::endl;

			break;
		}
	}

	if (!isFound) {

		std::cout << "No match!" << std::endl;
	}
}



int main() {

	std::srand(std::time(nullptr));

	std::cout << "~~~~~~~~~~~~~~~~~CONSTRUCTING FOREST~~~~~~~~~~~~~~~~~~~" << std::endl;

	const int treesCount = 5;

	Forest* trees = nullptr;

	createForest(treesCount, trees);

	searchForElf(treesCount, trees);

	delete[] trees;
	trees = nullptr;
}