/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:58:17 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/12 17:59:45 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain()
{
	if (DEBUG)
		std::cout << "Brain constructor was called" << std::endl;
}

Brain::~Brain()
{
	if (DEBUG)
		std::cout << "Brain destructor was called" << std::endl;
}