/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:51:33 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 12:06:36 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name
        	<< " cannot attack because it has no hit points!" << std::endl;
        return;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name
        	<< " cannot attack because it has no energy points!" << std::endl;
        return;
	}
	std::cout << "ClapTrap "<< this->name
		<< " attacks "<< target
		<< ", causing " << this->attackDamage
		<< " points of damage!" << std::endl;
	this->energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "\"High Fives Guys\"" << std::endl;
};
