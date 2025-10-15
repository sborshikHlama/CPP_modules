/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:27 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 23:44:57 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Tries to call the default construcot of the parent
Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	if (DEBUG)
		std::cout << "Dog constructor has been called" << std::endl;
};

Dog::Dog(const Dog& obj)
{
	this->type = obj.type;
	this->brain = new Brain(*(obj.brain));
	if (DEBUG)
		std::cout << "Dog Copy constructor has been called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	if (DEBUG)
		std::cout << "Dog destructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog& rightStamp)
{
	if (this != &rightStamp)
	{
		this->type = rightStamp.type;
		*(this->brain) = *(rightStamp.brain);
	}
	if (DEBUG)
		std::cout << "Dog has been assigned" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog makes sound: Meow" << std::endl;
}

void Dog::setIdea(int index, std::string const & idea)
{
	brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}
