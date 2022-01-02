#include "Smart_pointer.h"
#include "Classes.h"
#include <string>

Smart_ptr::Smart_ptr(const Smart_ptr& other)
{ 
	this->ptr = other.ptr;
	this->count = other.count;

	++(this->count);
}

Smart_ptr::~Smart_ptr() 
{
	dataDelete();
}

void Smart_ptr::dataDelete() 
{
	if (ptr != nullptr)
	{
		--(*count);
		if (*count == 0)
		{
			delete ptr;
			delete count;
		}
	}

	ptr = nullptr;
	count = nullptr;
}

Toy& Smart_ptr::operator*() { return *ptr; }

Smart_ptr& Smart_ptr::operator=(Smart_ptr& temp) 
{
	if (this == &temp)
		return *this;

	dataDelete();

	ptr = temp.ptr;
	count = temp.count;

	++(*count);
	
	return *this;
}

Smart_ptr makeSharedPtr(const std::string& name) 
{
	Smart_ptr temp;

	temp.setPtr(new Toy(name));
	temp.setCount(new int(1));

	return temp;
}