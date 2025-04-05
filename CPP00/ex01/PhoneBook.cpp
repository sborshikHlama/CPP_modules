/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:12:55 by aevstign          #+#    #+#             */
/*   Updated: 2025/04/05 09:39:29 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_counter = 0;
	_next_index = 0;
}

void PhoneBook::addContact(std::string firstname,std::string lastname,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	array_of_contacts[_next_index] = Contact(firstname, lastname, nickname, phone_number, darkest_secret);
	if (_counter < MAX_CONTACTS)
	{
		_counter++;
		_next_index++;
	}
	else
		_next_index = (_next_index + 1) % MAX_CONTACTS;
}

int	PhoneBook::getCounter()
{
	return (_counter);
}