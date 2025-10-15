/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:41:18 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 19:22:21 by aevstign         ###   ########.fr       */
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
		std::cout << "Animal copy constructor has been called" << std::endl;
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
		std::cout << "Animal has been asigned" << std::endl;
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