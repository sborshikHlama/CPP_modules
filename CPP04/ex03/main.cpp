#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int array_length = 10;

	Animal* animalArray[array_length];

	for (int i = 0; i < array_length; i++)
	{
		if (i <= array_length / 2)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}

	for (int i = 0; i < array_length; i++)
	{
		if (animalArray[i])
			delete animalArray[i];
	}
}