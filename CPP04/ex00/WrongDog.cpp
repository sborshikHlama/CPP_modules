/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:41 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:20:26 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

// Tries to call the default construcot of the parent
WrongDog::WrongDog()
{
	this->type = "WrongDog";
	if (DEBUG)
		std::cout << "WrongDog constructor has been called" << std::endl;
};

WrongDog::WrongDog(const WrongDog& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "WrongDog Copy constructor has been called" << std::endl;
}

WrongDog::~WrongDog()
{
	if (DEBUG)
		std::cout << "WrongDog destructor has been called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& rightStamp)
{
	if (this != &rightStamp)
		this->type = rightStamp.type;
	if (DEBUG)
		std::cout << "WrongDog has been assigned" << std::endl;
	return (*this);
}

void WrongDog::makeSound() const
{
	std::cout << "WrongDog makes sound: Bark" << std::endl;
}
