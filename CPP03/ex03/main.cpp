/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 12:04:49 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>


int	main()
{
	DiamondTrap pizdec("Vam pizda");
	pizdec.highFivesGuys();
	
	std::cout << pizdec.getHitPoints() << std::endl;
	std::cout << pizdec.getEnergyPoints() << std::endl;
	std::cout << pizdec.getAttackDamage() << std::endl;

	pizdec.whoAmI();
	pizdec.attack("someone");

	return(0);
}
