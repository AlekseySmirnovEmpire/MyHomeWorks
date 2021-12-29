#include "trains.h"
#include "clear.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>

std::mutex mtx;

void trainOnStation(Train& train) {

	std::lock_guard<std::mutex> guard(mtx);

	std::string answer;

	do {

		std::cout << "Train " << train.getName() << " is on station! Type \"depart\" to depart train from station: ";
		std::getline(std::cin, answer);

	} while (answer != "depart");

	std::cout << "Train " << train.getName() << " arraived!" << std::endl;
}

void trainOnWay(Train& train) {

	int time = train.getSpeed();

	while (time > 0) {

		std::this_thread::sleep_for(std::chrono::seconds(1));

		--time;

		std::cout << "Train " << train.getName() << " is in " << time << " sec from station." << std::endl;
	}

	trainOnStation(train);
}


int main()
{
	std::vector<Train> trains;

	createTrain(trains);
	
	std::vector<std::thread> tr;

	for (int i = 0; i < trains.size(); ++i) 
		tr.push_back(std::thread(trainOnWay, std::ref(trains[i])));

	for (auto& element : tr) 
		element.join();

	clear();

	std::cout << "===============All trains has arrived!=============" << std::endl;
}
