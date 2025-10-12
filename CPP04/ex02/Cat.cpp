/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:53:32 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/12 18:04:46 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Tries to call the default construcot of the parent
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	if (DEBUG)
		std::cout << "Cat constructor was called" << std::endl;
};

Cat::~Cat()
{
	delete this->brain;
	if (DEBUG)
		std::cout << "Cat destructor was called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes sound: Meow" << std::endl;
}
