/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:40:58 by aevstign          #+#    #+#             */
/*   Updated: 2025/04/04 23:44:20 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iomanip>


void	add_contact(PhoneBook &phoneBook)
{
	std::string firstname, lastname, nickname, phone_number, darkest_secret;
	std::cout << "Now, please enter the conact info" << std::endl;
	std::cin >> firstname;
	std::cin >> lastname;
	std::cin >> nickname;
	std::cin >> phone_number;
	std::cin >> darkest_secret;
	phoneBook.addContact(firstname, lastname, nickname, phone_number, darkest_secret);
	std::cout << "Contact was created" << std::endl;
}

void	search(PhoneBook phoneBook)
{
	int counter;

	counter = phoneBook.getCounter();
	for (int i = 0; i < counter; i++)
	{
		std::cout << "|" << i;
		std::cout << "|" << std::setw(10) << phoneBook.array_of_contacts[i].getFirstname();
		std::cout << "|" << std::setw(10) << phoneBook.array_of_contacts[i].getLastname();
		std::cout << "|" << std::setw(10) << phoneBook.array_of_contacts[i].getNickname();
	}
}

int	main(void)
{
	std::string	command;
	PhoneBook	phoneBook;
	
	std::getline(std::cin, command);
	while (1)
	{
		if (command.compare("ADD"))
			add_contact(phoneBook);
		else if (command.compare("EXIT"))
			return (0);
	}
}