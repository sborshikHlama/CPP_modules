/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/10 19:43:35 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	return(0);
}
