/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:15:08 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 11:14:53 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap {
private:
	std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &rigthStamp);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName(void);
	int getHitPoints(void);
	int getEnergyPoints(void);
	int getAttackDamage(void);
};