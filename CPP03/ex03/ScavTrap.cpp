/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:51:33 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 11:59:42 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name
        	<< " cannot attack because it has no hit points!" << std::endl;
        return;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name
        	<< " cannot attack because it has no energy points!" << std::endl;
        return;
	}
	std::cout << "ScavTrap "<< this->name
		<< " attacks "<< target
		<< ", causing " << this->attackDamage
		<< " points of damage!" << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate(void)
{
	std::cout << this->name << " is now in the guard mode" << std::endl;
};
