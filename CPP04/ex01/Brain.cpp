/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:58:17 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 22:23:59 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain()
{
	if (DEBUG)
		std::cout << "Brain constructor was called" << std::endl;
}

Brain::Brain(Brain const & obj)
{
	for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	if (DEBUG)
		std::cout << "Brain copy constructor has been called" << std::endl;
}

Brain::~Brain()
{
	if (DEBUG)
		std::cout << "Brain destructor was called" << std::endl;
}

Brain& Brain::operator=(const Brain& rightStamp)
{
	if (this != &rightStamp)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rightStamp.ideas[i];	
	if (DEBUG)
		std::cout << "Brain has been asigned" << std::endl;
	return (*this);
}

void Brain::setIdea(int index, std::string const & idea)
{
	if (index >= 0 && index <= 100)
		this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index <= 100)
		return (this->ideas[index]);
	return ("Wrong index");
}
