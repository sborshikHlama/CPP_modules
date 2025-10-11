/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 12:04:00 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap fragy1("Ninja");
	ScavTrap defenderA("Reinhart");

	fragy1.attack(defenderA.getName());
	defenderA.attack(fragy1.getName());
	defenderA.guardGate();
	
	ScavTrap defenderClone = defenderA;
	defenderClone.guardGate();
	return(0);
}
