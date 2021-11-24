#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>

struct Person
{
	std::string name = "unknown";
	int health = 0;
	int armour = 0;
	int damage = 0;
	int x = 0;
	int y = 0;
};

void initPlayer(Person& player) {
	std::cout << "Type name of your character: ";
	std::getline(std::cin, player.name);

	std::cout << "Input health count: ";
	std::cin >> player.health;
	std::cin.ignore();

	std::cout << "Input armour count: ";
	std::cin >> player.armour;
	std::cin.ignore();

	std::cout << "Input damage: ";
	std::cin >> player.damage;
	std::cin.ignore();
}

void initEnemies(std::vector<Person>& enemy) {
	std::srand(std::time(nullptr));
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i].name = "Enemy #" + std::to_string(i + 1);
		enemy[i].health = std::rand() % 101 + 50;
		enemy[i].armour = std::rand() % 51;
		enemy[i].damage = std::rand() % 16 + 15;
	}
}

void initField(std::vector<std::vector<char>>& field) {
	for (int i = 0; i < 40; i++) {
		std::vector<char> inVec;
		for (int j = 0; j < 40; j++) {
			inVec.push_back('.');
		}
		field.push_back(inVec);
	}
}

void initCharactersOnField(std::vector<std::vector<char>>& field, Person& player, std::vector<Person>& enemy) {
	std::srand(std::time(nullptr));

	player.x = std::rand() % 40;
	player.y = std::rand() % 40;

	field[player.x][player.y] = 'P';

	for (int i = 0; i < 5; i++) {
		do {
			enemy[i].x = std::rand() % 40;
			enemy[i].y = std::rand() % 40;
		} while (field[enemy[i].x][enemy[i].y] != '.');

		field[enemy[i].x][enemy[i].y] = 'E';
	}
}

void showField(std::vector<std::vector<char>>& field) {
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			std::cout << field[i][j];
		}
		std::cout << std::endl;
	}
}

bool isGameOver(Person& player, std::vector<Person> enemy) {
	for (int i = 0; i < 5; i++) {
		if (enemy[i].health > 0) return false;
	}
	return !(player.health > 0);
}

void saveGame(std::vector<std::vector<char>>& field, Person& player, std::vector<Person>& enemy, int turn) {
	std::ofstream file("save.bin", std::ios::binary);

	if (file.is_open()) {
		int length = player.name.length();

		file.write((char*)&length, sizeof(length));
		file.write(player.name.c_str(), length);
		file.write((char*)&player.health, sizeof(player.health));
		file.write((char*)&player.armour, sizeof(player.armour));
		file.write((char*)&player.damage, sizeof(player.damage));
		file.write((char*)&player.x, sizeof(player.x));
		file.write((char*)&player.y, sizeof(player.y));

		for (int i = 0; i < 5; ++i) {
			int len = enemy[i].name.length();

			file.write((char*)&len, sizeof(len));
			file.write(enemy[i].name.c_str(), len);
			file.write((char*)&enemy[i].health, sizeof(enemy[i].health));
			file.write((char*)&enemy[i].armour, sizeof(enemy[i].armour));
			file.write((char*)&enemy[i].damage, sizeof(enemy[i].damage));
			file.write((char*)&enemy[i].x, sizeof(enemy[i].x));
			file.write((char*)&enemy[i].y, sizeof(enemy[i].y));
		}

		for (int i = 0; i < 40; ++i) {
			for (int j = 0; j < 40; j++) {
				file.write((const char*)&field[i][j], sizeof(field[i][j]));
			}
		}

		file.write((char*)&turn, sizeof(turn));

		file.close();

		std::cout << "========GAME HAS BEEN SAVED!==========" << std::endl;
	}
	else {
		std::cout << "Error! File not found!" << std::endl;
	}
}

void loadGame(std::vector<std::vector<char>>& field, Person& player, std::vector<Person>& enemy, int turn) {

	std::ifstream file("D:\\Alex\\SkillBox_HomeWorks\\MyHomeWorks\\21_4\\21_4\\save.bin");

	if (file.is_open()) {
		int length;

		file.read((char*)&length, sizeof(length));
		player.name.resize(length);
		file.read((char*)player.name.c_str(), length);
		file.read((char*)&player.health, sizeof(player.health));
		file.read((char*)&player.armour, sizeof(player.armour));
		file.read((char*)&player.damage, sizeof(player.damage));
		file.read((char*)&player.x, sizeof(player.x));
		file.read((char*)&player.y, sizeof(player.y));

		for (int i = 0; i < 5; ++i) {
			int len;

			file.read((char*)&len, sizeof(len));
			enemy[i].name.resize(len);
			file.read((char*)enemy[i].name.c_str(), len);
			file.read((char*)&enemy[i].health, sizeof(enemy[i].health));
			file.read((char*)&enemy[i].armour, sizeof(enemy[i].armour));
			file.read((char*)&enemy[i].damage, sizeof(enemy[i].damage));
			file.read((char*)&enemy[i].x, sizeof(enemy[i].x));
			file.read((char*)&enemy[i].y, sizeof(enemy[i].y));
		}

		for (int i = 0; i < 40; ++i) {
			for (int j = 0; j < 40; j++) {
				file.read((char*)&field[i][j], sizeof(field[i][j]));
			}
		}

		file.read((char*)&turn, sizeof(turn));

		file.close();

		std::cout << "============GAME HAS BEEN LOADED=============" << std::endl;
	}
	else {
		std::cout << "======Error! Save game not found!======" << std::endl;
	}
}

void mathTemp(int& tempx, int& tempy, std::string& input) {
	if (input == "/top") {
		tempx = -1;
		tempy = 0;
	}
	else if (input == "/down") {
		tempx = 1;
		tempy = 0;
	}
	else if (input == "/left") {
		tempx = 0;
		tempy = -1;
	}
	else {
		tempx = 0;
		tempy = 1;
	}
}

void fightScene(Person& player, Person& enemy, std::vector<std::vector<char>>& field, int& x, int& y) {
	enemy.armour -= player.damage;

	std::cout << "------You hit enemy for " << player.damage << " damage----------" << std::endl;

	if (enemy.armour < 0) {
		enemy.health += enemy.armour;
		enemy.armour = 0;

		if (enemy.health <= 0) {
			std::cout << "!!!!!!!!!!!!!!!YOU'VE KILLED AN ENEMY!!!!!!!!!!!!!!!" << std::endl;

			field[enemy.x][enemy.y] = 'P';
			field[x][y] = '.';
			player.x = enemy.x;
			player.y = enemy.y;
		}
		else {
			enemy.armour = 0;

			std::cout << "Enemy health: " << enemy.health << std::endl;
		}		
	}
	else {
		std::cout << "Armour save an enemy! Now his armour: " << enemy.armour << std::endl;
	}

	player.armour -= enemy.damage;

	std::cout << "------Enemy hit you by " << enemy.damage << " damage----------" << std::endl;

	if (player.armour < 0) {
		player.health += player.armour;

		if (player.health <= 0) {
			std::cout << "!!!!!!!!!!YOU DIE!!!!!!!!!!!!" << std::endl;
		}
		else {
			player.armour = 0;

			std::cout << "Your current health: " << player.health << std::endl;
		}
	}
	else {
		std::cout << "Armour save you! Now your armour: " << player.armour << std::endl;
	}
}

void movePlayer(Person& player, std::string& input, std::vector<std::vector<char>>& field, std::vector<Person> enemy) {
	int tempx;
	int tempy;

	mathTemp(tempx, tempy, input);

	tempx += player.x;
	tempy += player.y;

	if (tempx < 40 && tempx >= 0 && tempy < 40 && tempy >= 0) {
		if (field[tempx][tempy] == '.') {
			field[player.x][player.y] = '.';
			field[tempx][tempy] = 'P';
			player.x = tempx;
			player.y = tempy;
		}
		else {
			int temp;

			for (int i = 0; i < 5; ++i) {
				temp = (enemy[i].x == tempx && enemy[i].y == tempy) ? i : 0;
			}

			fightScene(player, enemy[temp], field, tempx, tempy);
		}
	}
}

void moveEnemy(Person& player, std::string& input, std::vector<std::vector<char>>& field, std::vector<Person> enemy) {
	std::srand(std::time(nullptr));

	for (int i = 0; i < 5; ++i) {
		if (enemy[i].health > 0) {
			int tempx = 1 - std::rand() % 3;
			int tempy = tempx == 0 ? 1 - std::rand() % 3 : 0;

			tempx += enemy[i].x;
			tempy += enemy[i].y;

			if (tempx >= 0 && tempx < 40 && tempy < 40 && tempy <= 0) {
				if (field[tempx][tempy] == '.') {
					field[enemy[i].x][enemy[i].y] = '.';
					field[tempx][tempy] = 'E';
					enemy[i].x = tempx;
					enemy[i].y = tempy;
				}
				else if (field[tempx][tempy] == 'P') {
					fightScene(player, enemy[i], field, tempx, tempy);
				}
			}
		}
	}
}

int main() {
	Person player;
	
	std::vector<Person> enemy(5);

	initPlayer(player);
	initEnemies(enemy);

	std::vector<std::vector<char>> field;
	initField(field);

	int turn = 1;

	initCharactersOnField(field, player, enemy);

	showField(field);

	while (!isGameOver(player, enemy)) {
		std::cout << "~~~~~~~~~~~~~~~~~~~TURN " << std::to_string(turn) << "~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::string userInput;

		std::cout << "Type \"/save\" to save the game;" << std::endl;
		std::cout << "Type \"/load\" to load saved game;" << std::endl;
		std::cout << "Type \"/top\" to move top;" << std::endl;
		std::cout << "Type \"/left\" to move left;" << std::endl;
		std::cout << "Type \"/down\" to move down;" << std::endl;
		std::cout << "Type \"/right\" to move right;" << std::endl;

		std::getline(std::cin, userInput);

		if (userInput == "/save") {
			saveGame(field, player, enemy, turn);

			continue;
		}
		else if (userInput == "/load") {
			loadGame(field, player, enemy, turn);

			showField(field);
			
			std::cout << "---------------------------" << std::endl;

			std::cout << "Name: " << player.name << std::endl;
			std::cout << "Health: " << player.health << std::endl;
			std::cout << "Armour: " << player.armour << std::endl;
			std::cout << "Damage: " << player.damage << std::endl;

			continue;
		}
		else if (userInput == "/top" || userInput == "/left" || userInput == "/down" || userInput == "/right") {
			movePlayer(player, userInput, field, enemy);
		}
		else {
			std::cout << "=====Error! Wrong command!======" << std::endl;

			continue;
		}

		moveEnemy(player, userInput, field, enemy);

		showField(field);

		turn++;
	}

	std::cout << (player.health > 0 ? "=============YOU WIN=============" : "=============YOU LOSE=============") << std::endl;
}