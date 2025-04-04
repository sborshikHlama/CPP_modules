/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:12:55 by aevstign          #+#    #+#             */
/*   Updated: 2025/04/04 23:44:38 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact(std::string firstname,std::string lastname,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	array_of_contacts[_next_index] = Contact(firstname, lastname, nickname, phone_number, darkest_secret);
	_next_index = (_next_index + 1) % MAX_CONTACTS;
}

int	PhoneBook::getCounter()
{
	return (_counter)
}