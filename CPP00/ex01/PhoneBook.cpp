/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:12:55 by aevstign          #+#    #+#             */
/*   Updated: 2025/04/05 12:05:43 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->counter = 0;
	this->next_index = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(std::string firstname,std::string lastname,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	array_of_contacts[this->next_index] = Contact(firstname, lastname, nickname, phone_number, darkest_secret);
	if (this->counter < MAX_CONTACTS)
	{
		this->counter++;
		this->next_index++;
	}
	else
		this->next_index = (this->next_index + 1) % MAX_CONTACTS;
}

int	PhoneBook::getCounter()
{
	return (this->counter);
}