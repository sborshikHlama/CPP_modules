/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:40:58 by aevstign          #+#    #+#             */
/*   Updated: 2025/04/05 13:15:54 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

static int	validate_number(std::string number)
{
	for(std::string::size_type i = 0; i < number.length(); i++)
	{
		if (number[i] == ' ')
			i++;
		else if (number[i] < '0' || number[i] > '9')
			return 0;	
	}
	return (1);
}

void	add_contact(PhoneBook &phoneBook)
{
	std::string firstname, lastname, nickname, phone_number, darkest_secret;
	std::cout << "Now, please enter the conact info" << std::endl;
	std::cout << "Enter fristname" << std::endl;
	std::getline(std::cin, firstname);
	std::cout << "Enter lastname" << std::endl;
	std::getline(std::cin, lastname);
	std::cout << "Enter nickname" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number" << std::endl;
	std::getline(std::cin, phone_number);
	while (!validate_number(phone_number))
	{
		std::cout << "Please, enter a valid phone number" << std::endl;
		std::getline(std::cin, phone_number);
	}
	std::cout << "Enter darkest secret" << std::endl;
	std::getline(std::cin, darkest_secret);
	phoneBook.addContact(firstname, lastname, nickname, phone_number, darkest_secret);
	std::cout << "Contact was created\n" << std::endl;
}

void	display_value(std::string value)
{
	std::string	formatted;

	if (value.length() > 10)
		std::cout << "|" << std::setw(10) << value.substr(0, 9) + ".";
	else
		std::cout << "|" << std::setw(10) << value;
}

void	display_contact(PhoneBook phoneBook, int i)
{
	std::cout << "First Name: " << phoneBook.array_of_contacts[i].getFirstname() << std::endl; 
	std::cout << "Last Name: " << phoneBook.array_of_contacts[i].getLastname() << std::endl; 
	std::cout << "Nickname: " << phoneBook.array_of_contacts[i].getNickname() << std::endl; 
	std::cout << "Phone Number: " << phoneBook.array_of_contacts[i].getPhoneNumber() << std::endl; 
	std::cout << "Darkest Secret: " << phoneBook.array_of_contacts[i].getDarkestSecret() << std::endl; 
}

void	search(PhoneBook phoneBook)
{
	int counter;
	int	index;

	counter = phoneBook.getCounter();
	for (int i = 0; i < counter; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		display_value(phoneBook.array_of_contacts[i].getFirstname());
		display_value(phoneBook.array_of_contacts[i].getLastname());
		display_value(phoneBook.array_of_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "Enter the contact index" << std::endl;
	std::cin >> index;
	if (std::cin.fail() || index > phoneBook.getCounter())
	{
		std::cout << "Invalid Index!\n" << std::endl;
		std::cin.clear();
		return ;
	}
	std::cout << std::endl;
	display_contact(phoneBook, index);
	std::cout << std::endl;
}

int	main(void)
{
	std::string	command;
	PhoneBook	phoneBook;
	
	while (1)
	{
		std::cout << "Enter the command" << std::endl;
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			add_contact(phoneBook);
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "|" << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "Firstname"
			<< "|" << std::setw(10) << "Lastname"
			<< "|" << std::setw(10) << "Nickname"
			<< "|" << std::endl;
			search(phoneBook);
			// Dummy getline
			getline(std::cin, command);
		}
		else if (command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
