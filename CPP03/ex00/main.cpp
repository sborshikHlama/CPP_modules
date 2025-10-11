/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 12:17:15 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap warriorA("Bob");
	ClapTrap warriorB("Kelsa");
	ClapTrap warriorClone = warriorA;

	warriorA.attack(warriorB.getName());
	warriorB.attack(warriorA.getName());
	warriorClone.attack(warriorA.getName());
	
	std::cout << warriorA.getEnergyPoints() << std::endl;
	std::cout << warriorB.getEnergyPoints() << std::endl;
	std::cout << warriorClone.getEnergyPoints() << std::endl;
	return(0);
}
