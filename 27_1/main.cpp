#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Branch {
private:
	std::string name = "none";

public:
	Branch(const std::string& name) {

		this->name = name;
	}

	Branch() {}

	std::string getName() { return name; }
};

class Tree {

private:
	std::vector<std::vector<Branch>> tree;

public:
	Tree(const int& count);

	void searchElf(const std::string& name, int& index);

	int neighborsOfElf(const std::string& name, const int& index);
};

Tree::Tree(const int& count) {

	std::cout << "============Tree # " << count << "====================" << std::endl;

	int bigBranchesCount = std::rand() % 3 + 3;

	for (int i = 0; i < bigBranchesCount; ++i) {

		std::cout << "~~~~~~~~~~~~~~BIG BRANCH # " << i + 1 << "~~~~~~~~~~~~~~~~~~" << std::endl;

		int middleBranchesCount = std::rand() % 2 + 2;

		std::vector<Branch> tempBranch(middleBranchesCount);

		for (int j = 0; j < middleBranchesCount; ++j) {

			std::cout << "===============MIDDLE BRANCH # " << j + 1 << "====================" << std::endl;

			std::cout << "Input elf name (or none): ";
			std::string name;
			std::getline(std::cin, name);


			tempBranch[j] = Branch(name);
		}

		tree.push_back(tempBranch);
	}

	system("cls");
}

void Tree::searchElf(const std::string& name, int& index) {

	bool isFound = false;

	for (int i = 0; i < tree.size() && !isFound; ++i) {

		for (int j = 0; j < tree[i].size(); ++j) {

			if (tree[i][j].getName() == name) {

				index = i;

				isFound = true;
				break;
			}
		}
	}
}

int Tree::neighborsOfElf(const std::string& name, const int& index) {

	int output = 0;

	for (int i = 0; i < tree[index].size(); ++i) {

		if (tree[index][i].getName() != name && tree[index][i].getName() != "none") ++output;
	}

	return output;
}

void createForest(const int& count, std::vector<Tree>& forest) {

	for (int i = 0; i < count; ++i) {

		Tree* temp = new Tree(i + 1);

		forest.push_back(*temp);

		delete temp;
		temp = nullptr;
	}
}

void searchElfInForest(std::vector<Tree>& forest) {

	std::string name;

	std::cout << "Input elf's name: ";
	std::getline(std::cin, name);

	int index = -1;

	bool isFound = name != "none";

	for (int i = 0; i < forest.size() && !isFound; ++i) {

		forest[i].searchElf(name, index);

		isFound = index >= 0;

		if (isFound) {

			std::cout << name << " have " << forest[i].neighborsOfElf(name, index) << " neighbours!" << std::endl;

			break;
		}
	}

	if (!isFound) std::cout << "There is no elf with name " << name << "!" << std::endl;
}

int main() {

	std::srand(std::time(nullptr));

	const int treesCount = 5;

	std::vector<Tree> forest;

	createForest(treesCount, forest);

	searchElfInForest(forest);

	std::cout << "===================GOODBYE=====================" << std::endl;
}