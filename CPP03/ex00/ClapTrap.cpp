/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:15:11 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/08 14:03:36 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
{
	this->name = name;
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDamage = 0;
	std::cout << "Default constructor was called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor was called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap&righStamp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	*this = righStamp;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	this->name = obj.name;
	this->attackDamage = obj.attackDamage;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	std::cout << "Copy constructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	} else
	{
		std::cout << "Not enough points!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (amount > 0)
	{
		this->hitPoints += amount;
		std::cout << this->name << "repaired " << amount << " of points" << std::endl;
		this->energyPoints -= 1;
	} else
	{
		std::cout << "Amount cannot be 0!" << std::endl; 
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0)
	{
		this->hitPoints -= amount;
		std::cout << this->name << "took " << amount << " of Damage" << std::endl;
	} else
	{
		std::cout << "Amount cannot be 0!" << std::endl; 
	}
}

std::string	ClapTrap::getName(void)
{
	return(this->name);
}
