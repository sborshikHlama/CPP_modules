/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:07:05 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/12 20:10:06 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	if (DEBUG)
		std::cout << "Cure constructor was called" << std::endl;
}

Cure::~Cure()
{
	if (DEBUG)
		std::cout << "Cure destructor was called" << std::endl;
}
