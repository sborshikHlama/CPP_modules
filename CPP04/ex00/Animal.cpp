/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:27:36 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	if (DEBUG)
		std::cout << "Animal constructor has been called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "Animal Copy constructor has been called" << std::endl;
}

Animal::~Animal()
{
	if (DEBUG)
		std::cout << "Animal destructor has been called" << std::endl;
}

Animal& Animal::operator=(const Animal& rightStamp)
{
	if (this != &rightStamp)
		this->type = rightStamp.type;
	if (DEBUG)
		std::cout << "Animal has been assigned" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}