#include <iostream>
#include <string>

class Animal {

protected:
	virtual void voice() = 0;
};

class Cat : virtual public Animal {
public:
	virtual void voice() {

		std::cout << "Meow" << std::endl;
	}
};

class Dog : virtual public Animal {
public:
	virtual void voice() {
		
		std::cout << "Bark" << std::endl;
	}
};

void meeting(Animal* a, Animal* b) {

	Cat* one = dynamic_cast<Cat*>(a);
	Cat* two = dynamic_cast<Cat*>(b);

	if (one == nullptr && two == nullptr) {

		std::cout << "Woof Woof" << std::endl;
	}
	else if (one == nullptr) {

		std::cout << "Bark Meow" << std::endl;
	}
	else if (two == nullptr) {

		std::cout << "Meow Bark" << std::endl;
	}
	else {

		std::cout << "Purr Purr" << std::endl;
	}
}

int main() {

	Animal* cat = new Cat();
	Animal* dog = new Dog();
	
	meeting(cat, dog);

}