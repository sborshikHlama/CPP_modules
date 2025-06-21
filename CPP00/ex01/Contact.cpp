//
// Created by Arsenii on 15.06.2025.
//

#include "Contact.h"
Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(std::string info[])
{
    this->firstname = info[0];
    this->lastname = info[1];
    this->nickname = info[2];
    this->phone_number = info[3];
    this->darkest_secret = info[4];
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
