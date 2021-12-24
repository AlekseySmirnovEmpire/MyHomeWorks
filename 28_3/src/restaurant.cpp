#include "restaurant.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <vector>

std::vector<eDishes> orders;
std::vector<eDishes> doneOrders;

std::mutex orderQueue;
std::mutex makingQueue;

int deliveriesDone = 0;

std::string showDish(const eDishes& dish) {

	switch (dish)
	{
	case PIZZA:
		return "pizza";
	
	case SUSHI:
		return "sushi";

	case SOUP:
		return "soup";

	case STEAK:
		return "steak";

	case SALAD:
		return "salad";
	}
}

void createOrder() {

	std::srand(std::time(nullptr));

	while(true) {

		int timer = std::rand() % 6 + 5;
		std::this_thread::sleep_for(std::chrono::seconds(timer));

		orderQueue.lock();

		eDishes newDish = static_cast<eDishes>(std::rand() % AMOUNT);

		std::cout << "Made order: " << showDish(newDish) << std::endl;

		orders.push_back(newDish);

		orderQueue.unlock();
	}
}

void makeOrder() {

	std::srand(std::time(nullptr));

	while (true) {

		if (orders.size() != 0) {

			orderQueue.lock();

			int timer = std::rand() % 11 + 5;

			for (int i = 0; orders.size() > 0; ++i) {

				std::cout << "~~~~~~~~Kitchen start making " << showDish(orders[i]) << std::endl;

				std::this_thread::sleep_for(std::chrono::seconds(timer));

				makingQueue.lock();
				doneOrders.push_back(orders[i]);
				makingQueue.unlock();

				std::cout << "~~~~~~~~~~~~" << showDish(orders[i]) << " is DONE!~~~~~~~~~~~~" << std::endl;

				orders.pop_back();
			}

			orderQueue.unlock();
		}
	}
}

void makeDelivery() {

	while (deliveriesDone < 10) {

		std::this_thread::sleep_for(std::chrono::seconds(30));

		if (doneOrders.size() != 0) {

			makingQueue.lock();

			std::cout << "========DELIVERY=========" << std::endl;

			for (int i = 0; doneOrders.size() > 0; ++i) {

				std::cout << i + 1 << ". " << showDish(doneOrders[i]) << " is on way!" << std::endl;

				doneOrders.pop_back();
			}

			makingQueue.unlock();
			++deliveriesDone;
		}
	}
}