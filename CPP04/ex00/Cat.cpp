/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:27 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:14:36 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Tries to call the default construcot of the parent
Cat::Cat()
{
	this->type = "Cat";
	if (DEBUG)
		std::cout << "Cat constructor has been called" << std::endl;
};

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "Cat Copy constructor has been called" << std::endl;
}

Cat::~Cat()
{
	if (DEBUG)
		std::cout << "Cat destructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat& rightStamp)
{
	if (this != &rightStamp)
		this->type = rightStamp.type;
	if (DEBUG)
		std::cout << "Cat has been assigned" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat makes sound: Meow" << std::endl;
}
