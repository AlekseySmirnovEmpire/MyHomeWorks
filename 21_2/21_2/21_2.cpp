#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum eBuildingTypes {
	HOUSE,
	GARAGE,
	BARN,
	BATHHOUSE
};

enum eRoomsType {
	BEDROOM = 1,
	KITCHEN,
	BATHROOM,
	CHILDRENROOM,
	MEETINGROOM
};

struct Garage
{
	bool isFound = false;
	double square = 0;
	eBuildingTypes type = HOUSE;
};

struct Barn
{
	bool isFound = false;
	double square = 0;
	eBuildingTypes type = HOUSE;
};

struct BathHouse
{
	bool isFound = false;
	bool isStove = false;
	double square = 0;
	eBuildingTypes type = HOUSE;
};

struct Room
{
	double square = 0;
	eRoomsType type = BATHROOM;
};

struct Floor
{
	double height = 0;
	std::vector<Room> room;
};

struct House
{
	bool isStove = false;
	std::vector<Floor> floor;
	eBuildingTypes type = HOUSE;
};

struct Region
{
	House home;
	BathHouse bathhouseStruct;
	Garage garageStruct;
	Barn barnStruck;
};

void inputBuilding(Region& reg, int* counter) {
	std::cout << "Whats' the types of building? Type:" << std::endl;
	std::cout << "\"" << GARAGE <<"\" for garage;" << std::endl;
	std::cout << "\"" << BARN << "\" for barn;" << std::endl;
	std::cout << "\"" << BATHHOUSE << "\" for bathhouse;" << std::endl;

	int answer;
	std::cin >> answer;
	std::cin.ignore();

	while (answer < GARAGE || answer > BATHHOUSE) {
		std::cout << "Wrong! Try again: ";
		std::cin >> answer;
		std::cin.ignore();
	}

	if (answer == GARAGE && !reg.garageStruct.isFound) {
		reg.garageStruct.isFound = true;

		std::cout << "What's the square of garage: ";
		std::cin >> reg.garageStruct.square;
		std::cin.ignore();

		reg.garageStruct.type = GARAGE;

		(*counter)--;

		std::cout << "------------------------------------" << std::endl;
	}
	else if (answer == BARN && !reg.barnStruck.isFound) {
		reg.barnStruck.isFound = true;

		std::cout << "What's the square of barn: ";
		std::cin >> reg.barnStruck.square;
		std::cin.ignore();

		reg.barnStruck.type = BARN;

		(*counter)--;

		std::cout << "------------------------------------" << std::endl;
	}
	else if (answer == BATHHOUSE && !reg.bathhouseStruct.isFound) {
		reg.bathhouseStruct.isFound = true;

		std::cout << "Have bathhouse any stove? (y/n) ";
		char answer;
		std::cin >> answer;
		std::cin.ignore();

		reg.bathhouseStruct.type = BATHHOUSE;

		reg.bathhouseStruct.isStove = answer == 'y';

		std::cout << "What's the square of bathhouse: ";
		std::cin >> reg.bathhouseStruct.square;
		std::cin.ignore();

		(*counter)--;

		std::cout << "------------------------------------" << std::endl;
	}
	else {
		std::cout << "Wrong, you have already write this. Try again!" << std::endl;
	}
}

void roomType(Room& rooms, eRoomsType roomType) {
	
	std::cout << "What's the square of room: ";
	std::cin >> rooms.square;
	std::cin.ignore();

	rooms.type = roomType;

}

void inputRoom(Room& rooms) {
	std::cout << "What's the type of room? Type:" << std::endl;
	std::cout << "\"" << BEDROOM << "\" for bedroom;" << std::endl;
	std::cout << "\"" << KITCHEN << "\" for kitchen;" << std::endl;
	std::cout << "\"" << BATHROOM << "\" for bathroom;" << std::endl;
	std::cout << "\"" << CHILDRENROOM << "\" for children room;" << std::endl;
	std::cout << "\"" << MEETINGROOM << "\" for meetingroom;" << std::endl;

	int answer;
	std::cin >> answer;
	std::cin.ignore();

	while (answer < BEDROOM || answer > MEETINGROOM) {
		std::cout << "Wrong input, try again: ";
		std::cin >> answer;
		std::cin.ignore();
	}

	if (answer == BEDROOM) {
		std::cout << "~~~~~~~~~~~~~~BEDROOM~~~~~~~~~~~~~~" << std::endl;

		roomType(rooms, BEDROOM);
	}
	else if (answer == KITCHEN) {
		std::cout << "~~~~~~~~~~~~~~KITCHEN~~~~~~~~~~~~~~" << std::endl;

		roomType(rooms, KITCHEN);
	}
	else if (answer == BATHROOM) {
		std::cout << "~~~~~~~~~~~~~~BATHROOM~~~~~~~~~~~~~~" << std::endl;

		roomType(rooms, BATHROOM);
	}
	else if (answer == CHILDRENROOM) {
		std::cout << "~~~~~~~~~~~~~~CHILDRENROOM~~~~~~~~~~~~~~" << std::endl;

		roomType(rooms, CHILDRENROOM);
	}
	else if (answer == MEETINGROOM) {
		std::cout << "~~~~~~~~~~~~~~MEETINGROOM~~~~~~~~~~~~~~" << std::endl;

		roomType(rooms, MEETINGROOM);
	}

	std::cout << "-----------------------------------" << std::endl;
}

void inputFloor(Floor& floor) {
	std::cout << "Input height of the floor: ";
	std::cin >> floor.height;
	std::cin.ignore();

	std::cout << "How many rooms on this floor: ";
	int roomsCounter;
	std::cin >> roomsCounter;
	std::cin.ignore();

	while (roomsCounter < 1) {
		std::cout << "Wrong, try again: ";
		std::cin >> roomsCounter;
		std::cin.ignore();
	}

	floor.room.resize(roomsCounter);

	for (int i = 0; i < roomsCounter; i++) {
		std::cout << "---------------" << i + 1 << " ROOM---------------" << std::endl;
		
		inputRoom(floor.room[i]);
	}

	std::cout << "-------------------------------" << std::endl;
}

void inputHouse(House& home) {
	std::cout << "Have house any stove? (y/n) ";
	char answer;
	std::cin >> answer;
	std::cin.ignore();
	home.isStove = answer == 'y';

	std::cout << "How many floors in the house: ";
	int floorsCounter;
	std::cin >> floorsCounter;
	std::cin.ignore();

	while (floorsCounter < 1) {
		std::cout << "Wrong, try again: ";
		std::cin >> floorsCounter;
		std::cin.ignore();
	}

	home.floor.resize(floorsCounter);

	for (int i = 0; i < floorsCounter; i++) {
		std::cout << "==============" << i + 1 << " FLOOR==============" << std::endl;
		
		inputFloor(home.floor[i]);
	}
	
	std::cout << "-------------------------------------------" << std::endl;
}

void inputRegion(std::vector<Region>& regions, int count) {
	for (int i = 0; i < count; i++) {

		std::cout << "~~~~~~~~~~~~~~~~~" << i + 1 << " REGION~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cout << "How many buildings except house is on area: ";
		int housesCounter;
		std::cin >> housesCounter;
		std::cin.ignore();
		
		std::cout << "---------------INPUT HOUSE---------------" << std::endl;

		inputHouse(regions[i].home);

		while (housesCounter > 0) {
			std::cout << "-----------------INPUT OTHER BUILDINGS-----------------" << std::endl;

			inputBuilding(regions[i], &housesCounter);
		}
	}
}

double totalSquare(std::vector<Region>& reg) {

	double temp = 0;
	
	for (int i = 0; i < reg.size(); i++) {

		temp += reg[i].barnStruck.square + reg[i].bathhouseStruct.square + reg[i].garageStruct.square;

		for (int j = 0; j < reg[i].home.floor.size(); j++) {
			for (int k = 0; k < reg[i].home.floor[j].room.size(); k++) {
				temp += reg[i].home.floor[j].room[k].square;
			}
		}
	}

	return temp;
	
}

int main() {

	std::cout << "~~~~~~~~~~~~~~~~~~WELCOME!~~~~~~~~~~~~~~~~~~" << std::endl;

	int regionsCount;
	std::cout << "Input amount of regions in village: ";
	std::cin >> regionsCount;
	std::cin.ignore();

	std::vector<Region> regions(regionsCount);

	inputRegion(regions, regionsCount);

	std::cout << "Total square = " << totalSquare(regions) << std::endl;

	std::cout << "~~~~~~~~~~~~~~~~~~GOODBYE!~~~~~~~~~~~~~~~~~~" << std::endl;
}