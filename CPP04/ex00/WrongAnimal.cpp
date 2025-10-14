/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:54 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:26:09 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	if (DEBUG)
		std::cout << "WrongAnimal constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "WrongAnimal copy constructor has been called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	if (DEBUG)
		std::cout << "WrongAnimal destructor has been called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rightStamp)
{
	if (this != &rightStamp)
		this->type = rightStamp.type;
	if (DEBUG)
		std::cout << "WrongAnimal has been assigned" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
