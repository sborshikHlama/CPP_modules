#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	const WrongAnimal* w = new WrongAnimal();
	w->makeSound();
	const WrongAnimal* wD = new WrongDog();
	wD->makeSound();
	const WrongAnimal* wC = new WrongCat();
	wC->makeSound();
	delete i;
	delete j;
	delete meta;
	delete w;
	delete wD;
	delete wC;
}
