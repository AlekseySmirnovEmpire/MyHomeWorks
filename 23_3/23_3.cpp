#include <iostream>

//#define SPRING

#define AUTUMN

//#define SUMMER

//#define WINTER

int main() {

#ifdef SPRING
	std::cout << "SPRING" << std::endl;
#endif

#ifdef SUMMER
	std::cout << "SUMMER" << std::endl;
#endif 

#ifdef AUTUMN
	std::cout << "AUTUMN" << std::endl;
#endif 

#ifdef WINTER
	std::cout << "WINTER" << std::endl;
#endif 
}