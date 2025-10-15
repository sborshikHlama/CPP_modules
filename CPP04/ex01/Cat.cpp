/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:27 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 23:21:54 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Tries to call the default construcot of the parent
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	if (DEBUG)
		std::cout << "Cat constructor has been called" << std::endl;
};

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	this->brain = obj.brain;
	if (DEBUG)
		std::cout << "Cat Copy constructor has been called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	if (DEBUG)
		std::cout << "Cat destructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat& rightStamp)
{
	if (this != &rightStamp)
	{
		this->type = rightStamp.type;
		this->brain = rightStamp.brain;
	}
	if (DEBUG)
		std::cout << "Cat has been assigned" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat makes sound: Meow" << std::endl;
}

void Cat::setIdea(int index, std::string const & idea)
{
	brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}
