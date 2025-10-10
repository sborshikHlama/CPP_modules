/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:16:34 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/08 14:01:51 by aevstign         ###   ########.fr       */
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
	return(0);
}
