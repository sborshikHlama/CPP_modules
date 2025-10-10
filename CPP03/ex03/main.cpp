/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/10 20:49:13 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap warriorA("Bob");
	ClapTrap warriorB("Kelsa");
	ClapTrap warriorClone = warriorA;

	warriorA.attack(warriorB.getName());
	warriorB.attack(warriorA.getName());
	warriorClone.attack(warriorA.getName());

	ScavTrap defenderA("Reinhart");
	defenderA.attack(warriorA.getName());
	defenderA.guardGate();
	
	ScavTrap defenderClone = defenderA;
	defenderClone.guardGate();

	DiamondTrap pizdec("Vam pizda");
	pizdec.highFivesGuys();
	
	std::cout << pizdec.getHitPoints() << std::endl;
	std::cout << pizdec.getEnergyPoints() << std::endl;
	std::cout << pizdec.getAttackDamage() << std::endl;

	pizdec.whoAmI();

	return(0);
}
