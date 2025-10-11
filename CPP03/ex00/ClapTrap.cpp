/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:15:11 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 11:14:58 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
{
	this->name = name;
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap constructor was called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor was called" << std::endl;
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

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->hitPoints += amount;
		std::cout << this->name
			<< "repaired " << amount
			<< " of points" << std::endl;
		this->energyPoints -= 1;
	} else
	{
		std::cout << "Not enough points!" << std::endl; 
	}
	this->hitPoints += amount;
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " repairs itself, gaining "
    << amount << " hit points! Current HP: " << this->hitPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " doesn't have any hitPoints left" << std::endl;
		return ;
	}
	this->hitPoints -= (amount >= this->hitPoints)? 0: this->hitPoints - amount;
	std::cout << this->name << "took " << amount << " of Damage" << std::endl;	
}

std::string	ClapTrap::getName(void)
{
	return(this->name);
}

int	ClapTrap::getHitPoints(void)
{
	return(this->hitPoints);
}

int	ClapTrap::getEnergyPoints(void)
{
	return(this->energyPoints);
}

int	ClapTrap::getAttackDamage(void)
{
	return(this->attackDamage);
}
