#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal* dog = new Dog();
    // const Animal* cat = new Cat();

    // delete dog; // Is destructor correct
    // delete cat;

	Dog dog1;
    dog1.setIdea(0, "Fetch the ball!");
    Dog dog2 = dog1;

    std::cout << "Dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog2.setIdea(0, "Chase the cat!");

    std::cout << "Dog1 idea after change: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea after change: " << dog2.getIdea(0) << std::endl;

}