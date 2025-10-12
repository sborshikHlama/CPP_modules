#include "Dog.hpp"
#include "Brain.hpp"

// Tries to call the default construcot of the parent
Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	if (DEBUG)
		std::cout << "Dog constructor was called" << std::endl;
};

Dog::~Dog()
{
	delete this->brain;
	if (DEBUG)
		std::cout << "Dog destructor was called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog makes sound: Bark" << std::endl;
}
