/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:14 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:18:09 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Tries to call the default construcot of the parent
Dog::Dog()
{
	this->type = "Dog";
	if (DEBUG)
		std::cout << "Dog constructor has been called" << std::endl;
};

Dog::Dog(const Dog& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "Dog Copy constructor has been called" << std::endl;
}

Dog::~Dog()
{
	if (DEBUG)
		std::cout << "Dog destructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog& rightStamp)
{
	if (this != &rightStamp)
		this->type = rightStamp.type;
	if (DEBUG)
		std::cout << "Dog has been assigned" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog makes sound: Bark" << std::endl;
}
