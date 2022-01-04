#pragma once
#include "Classes.h"
#include <string>

class Smart_ptr
{
private:
	Toy* ptr;
	int* count;

public:
	Smart_ptr() {}
	Smart_ptr(const Smart_ptr& other);
	~Smart_ptr();

	void dataDelete();

	void setPtr(Toy* ptr) { this->ptr = ptr; }
	void setCount(int* count) { this->count = count; }

	Toy& operator*();
	Smart_ptr& operator=(Smart_ptr& toy);
};

Smart_ptr makeSharedPtr(const std::string& name);