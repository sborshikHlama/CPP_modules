/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:55:33 by aevstign          #+#    #+#             */
/*   Updated: 2025/03/29 10:03:02 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	_first_name = firstname;
	_last_name = lastname;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}

std::string Contact::getFirstname()
{
	return (_first_name);
}

std::string Contact::getLastname()
{
	return (_last_name);
}

std::string Contact::getNickname()
{
	return (_nickname);
}

std::string Contact::getPhoneNumber()
{
	return (_phone_number);
}

std::string Contact::getDarkestSecret()
{
	return (_darkest_secret);
}
