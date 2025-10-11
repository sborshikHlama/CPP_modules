/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 12:23:19 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>


int	main()
{
	DiamondTrap labubu("Di");
	labubu.highFivesGuys();
	
	std::cout << labubu.getHitPoints() << std::endl;
	std::cout << labubu.getEnergyPoints() << std::endl;
	std::cout << labubu.getAttackDamage() << std::endl;

	labubu.whoAmI();
	labubu.attack("someone");

	return(0);
}
