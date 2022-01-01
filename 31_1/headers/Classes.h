#pragma once
#include "Smart_pointer.h"
#include <string>

class Toy
{
private:
	std::string name = "";

public:
	Toy(const std::string& name) 
	{
		this->name = name;
	}
	Toy() : Toy("None") {};
};

class Dog
{
private:
	std::string name;
	int age;
	Smart_ptr lovelyToy;

public:
	Dog(const std::string& name) 
	{
		this->name = name;
	}
	Dog(const std::string& name, const int& age) : Dog(name)
	{
		this->age = (age < 0 || age > 30) ? 0 : age;
	}
	Dog(const std::string& name, const int& age, Smart_ptr inToy) : Dog(name, age)
	{
		lovelyToy = inToy;
	}
	Dog() : Dog("Uknown", 0, makeSharedPtr("Uknown")) {}
};