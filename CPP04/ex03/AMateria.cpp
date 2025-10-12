/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:38:48 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/12 20:01:43 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type)
{
	if (DEBUG)
		std::cout << "AMateria constructor was called" << std::endl;
}

AMateria::~AMateria()
{
	if (DEBUG)
		std::cout << "AMateria destructor was called" << std::endl;
}

AMateria::AMateria(AMateria const & obj): type(obj.type){}

AMateria& AMateria::operator=(AMateria const & rightStamp){}

std::string const &AMateria::getType() const
{
	return (this->type);
}