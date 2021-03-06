#include <iostream>

void initArray(int arr[][6], bool VIP, int count) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			arr[i][j] = count;
		}
	}
	if (VIP) {
		arr[0][0]++;
		arr[0][1]++;
	}
}

void outputArray(int arr[][6]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, ".UTF8");

	/*?? ?????? ????????? ??????????? ????????? ???????? ?????????? ??????, ???????????? ???? ?? 12 ??????, 
	2 ?? ??? - ??? ????? VIP, ??? ??????????? ????? ???? ? ????? ?? ????? ?????. ???? ??????????? ? ?????, 
	????? ??????????? ? ??? ????. ?????? ????????? ?????? ???? ?????????? ??????????????? ???????. 
	??-?????? ???????? ??????? - ?? ??? ?? ??????? ???????? (?????, ?????, ???), ???? ???? ????????? ?????????????? 
	??????? ??? VIP-??????, ??? ???????. ??? ?????????? ??????????. ?????? ???????, ??????? ?? ??? - ??? 
	??????? ? ??????? ?????, ??? VIP ?????? +1 ??????? ??? ???????. ?? ? ??????? ???? - ???? ??? ???????, ???????! 
	???????? ??????????????? ????????? ??????? ??? ?????????? ????????, ?????? ? ??????? ? ?????????????????? ?? ??? ???????.

	??????, ??? ??? ?? ???. ? ???? ???????, ??? ????? ?????????????, ?????????? ????????? ???????. 
	????????? ?? 5-?? ????? ??????? ???? ???? ?????? ?????? ? ???????? ? ??????? ?? ?????? ????? ??? ?????????? 
	??? ???? ????. ? ???????? ????? ?? ?????? ???? ? ??????????? ??????????? ???? ???????? ?????. ????? ????? 
	???? ?? VIP ?????? (?????) ?????????? ????? ?????? ? ??? ? ???? ??? ???????, ? ??? ???? ???? ??? ?????????. 
	?? ????????????? ???????? ?????? ? ???? ???? ????????? ???????, ??? ???? ?????? ??????, ??????? ???????? ??? 
	? ???? - ?? ????????. ?????? ??? ????????????!*/

	int spoons[2][6], forks[2][6], dishes[2][6], chairs[2][6], knifes[2][6];

	initArray(knifes, false, 3);

	initArray(forks, false, 3);

	initArray(spoons, true, 3);

	initArray(dishes, true, 2);

	initArray(chairs, false, 1);

	chairs[0][4]++;

	spoons[0][0]--;
	
	dishes[0][0]--;

	std::cout << "Spoons: " << std::endl;
	outputArray(spoons);

	std::cout << "Forks: " << std::endl;
	outputArray(forks);

	std::cout << "Knifes: " << std::endl;
	outputArray(knifes);

	std::cout << "Dishes: " << std::endl;
	outputArray(dishes);

	std::cout << "Chairs: " << std::endl;
	outputArray(chairs);
}