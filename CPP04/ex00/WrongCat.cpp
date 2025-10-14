/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:36 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:25:15 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Tries to call the default construcot of the parent
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	if (DEBUG)
		std::cout << "WrongCat constructor has been called" << std::endl;
};

WrongCat::WrongCat(const WrongCat& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "WrongCat Copy constructor has been called" << std::endl;
}

WrongCat::~WrongCat()
{
	if (DEBUG)
		std::cout << "WrongCat destructor has been called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rightStamp)
{
	if (this != &rightStamp)
		this->type = rightStamp.type;
	if (DEBUG)
		std::cout << "WrongCat has been assigned" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat makes sound: Meow" << std::endl;
}
