/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 12:20:06 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap warriorA("Bob");
	ScavTrap defenderA("Reinhart");
	
	defenderA.attack(warriorA.getName());
	defenderA.guardGate();

	ScavTrap defenderClone = defenderA;
	defenderClone.guardGate();
	std::cout << defenderA.getEnergyPoints() << std::endl;

	return(0);
}
