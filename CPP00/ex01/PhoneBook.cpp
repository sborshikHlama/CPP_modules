//
// Created by Arsenii on 15.06.2025.
//

#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
    this->counter = 0;
    this->next_index = 0;
}

PhoneBook::~PhoneBook() {}

// Display functions

void	PhoneBook::displayValue(const std::string &value, const bool full) {
    std::string	formatted;

    if (value.length() > 10 && !full)
        std::cout << "|" << std::setw(10) << value.substr(0, 9) + ".";
    else
        std::cout << "|" << std::setw(10) << value;
}

void	PhoneBook::displayContact(const Contact &contact, const bool full) {
    PhoneBook::displayValue(contact.getFirstname(), full);
    PhoneBook::displayValue(contact.getLastname(), full);
    PhoneBook::displayValue(contact.getNickname(), full);
	if (full)
	{
		PhoneBook::displayValue(contact.getPhoneNumber(), full);
		PhoneBook::displayValue(contact.getDarkestSecret(), full);
	}
}

// Subject functions

void PhoneBook::add(std::string info[])
{
    contact[this->next_index] = Contact(info);
    if (this->counter < MAX_CONTACTS)
        this->counter++;
    this->next_index = (this->next_index + 1) % MAX_CONTACTS;
}

void	PhoneBook::search() const {
    int	index;

	for (int i = 0; i < this->getCounter(); i++)
	{
		std::cout << "|" << std::setw(10) << i;
		PhoneBook::displayContact(this->contact[i], false);
		std::cout << "|" << std::endl;
	}
    std::cout << "Enter the contact index" << std::endl;
    std::cin >> index;
    if (std::cin.fail() || index > this->getCounter() - 1 || index < 0)
    {
        std::cout << "Invalid Index!\n" << std::endl;
        std::cin.clear();
        return ;
    }
    std::cout << std::endl;
    PhoneBook::displayContact(this->contact[index], true);
    std::cout << std::endl;
}

int PhoneBook::getCounter() const {
    return (this->counter);
}

bool	PhoneBook::validateNumber(const std::string &number) {
    for(std::string::size_type i = 0; i < number.length(); i++)
    {
        if (number[i] == ' ')
            i++;
        else if (number[i] < '0' || number[i] > '9')
            return (false);
    }
    return (true);
}

bool	PhoneBook::getInput(std::string &dst)
{
    std::getline(std::cin, dst);
	if (dst.empty())
	{
		std::cout << "Field cannot be empty!" << std::endl;
		return (false);
	}
	for (std::string::size_type i = 0; i < dst.length(); i++)
	{
		if (dst[i] == ' ' || dst[i] == '\t')
		{
			std::cout << "Field cannot have empty symbols!" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	PhoneBook::promptInput(std::string label, std::string &dst)
{
	std::cout << "Enter: " << label << std::endl;
	if (!PhoneBook::getInput(dst)) return (false);
	return (true);
}

void	PhoneBook::readInput() {
    std::string info[5];
	std::string labels[5] = {"First Name", "Last Name", "Nickname",
		"Phone Number", "Darkest Secret"};

    std::cout << "Now, please enter the contact info" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (!PhoneBook::promptInput(labels[i], info[i])) return;
		if (i == 3 && !PhoneBook::validateNumber(info[3]))
		{
			std::cout << "Number can contain only digits!" << std::endl;
			return;
		}
	}
    this->add(info);
    std::cout << "Contact was created\n" << std::endl;
}

void    PhoneBook::loop()
{
    std::string	command;

    while (true)
    {
        std::cout << "Enter the command" << std::endl;
        std::getline(std::cin, command);
        if (command == "ADD" || command == "add" || command == "a")
            this->readInput();
        else if (command == "SEARCH" || command == "search" || command == "s")
        {
            std::cout << "|" << std::setw(10) << "Index"
            << "|" << std::setw(10) << "Firstname"
            << "|" << std::setw(10) << "Lastname"
            << "|" << std::setw(10) << "Nickname"
            << "|" << std::endl;
            this->search();
            // Dummy getline
            getline(std::cin, command);
        }
        else if (command == "EXIT" || command == "exit" || command == "e")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
}
