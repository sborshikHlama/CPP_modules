/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:55:33 by aevstign          #+#    #+#             */
/*   Updated: 2025/04/05 12:04:19 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string Contact::getFirstname() const {
	return (this->firstname);
}

std::string Contact::getLastname() const {
	return (this->lastname);
}

std::string Contact::getNickname() const {
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const {
	return (this->phone_number);
}

std::string Contact::getDarkestSecret() const {
	return (this->darkest_secret);
}
