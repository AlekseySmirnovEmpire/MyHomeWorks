#include "classes.h"
#include <iostream>
#include <thread>
#include <map>
#include <mutex>

std::mutex mathScores;

Sportsman::Sportsman() {

	std::cout << "Input sportsman's name: ";
	std::getline(std::cin, this->name);

	std::cout << "Input his speed: ";
	std::cin >> this->speed;
	std::cin.ignore();
}

void startSwim(Sportsman& sportsman, std::map<int, std::string>& score) {

	int distance = 100;

	int time = 0;

	while (distance > 0) {

		distance -= sportsman.getSpeed();

		std::this_thread::sleep_for(std::chrono::seconds(1));
		++time;

		std::cout << sportsman.getName() << " swimming for " << time << " seconds!" << std::endl;
	}

	mathScores.lock();

	score.emplace(score.size() + 1, sportsman.getName());

	std::cout << "================" << sportsman.getName() << " have finished!=================" << std::endl;

	mathScores.unlock();
}

void showScore(std::map<int, std::string>& score) {

	std::cout << "=============SCORE=============" << std::endl;

	auto it = score.begin();

	while (it != score.end()) {

		std::cout << it->first << ". " << it->second << std::endl;

		++it;
	}
}