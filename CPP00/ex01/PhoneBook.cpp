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
void	PhoneBook::displayContact(const Contact &contact, const bool full)
{
	std::pair<std::string, std::string> const contact_fields[5] = {
		std::make_pair("First Name: ", contact.getFirstname()),
		std::make_pair("Last Name: ", contact.getLastname()),
		std::make_pair("Nickname: ", contact.getNickname()),
		std::make_pair("Phone: ", contact.getPhoneNumber()),
		std::make_pair("Darkest secret: ", contact.getDarkestSecret())
	};

	for (int i = 0; i < 5; i++)
	{
		if (full)
			std::cout << contact_fields[i].first  << contact_fields[i].second << std::endl;
		else
		{
			if (i == 3)
				break;
			std::string formatted;
			formatted = contact_fields[i].second.length() > 10
			 ? contact_fields[i].second.substr(0, 9) + "."
				: contact_fields[i].second;
			std::cout << "|" << std::setw(10) << formatted;
		}
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
	char leftover;
	std::string str;

	for (int i = 0; i < this->getCounter(); i++)
	{
		std::cout << "|" << std::setw(10) << i;
		PhoneBook::displayContact(this->contact[i], false);
		std::cout << "|" << std::endl;
	}
    std::cout << "Enter the contact index" << std::endl;
	std::getline(std::cin, str);
	std::istringstream iss(str);
	iss >> index;
    if (iss.fail() || index >= this->getCounter()
		|| index < 0 || (iss >> leftover))
    {
        std::cout << "Invalid Index!\n" << std::endl;
        iss.clear();
        return ;
    }
    std::cout << std::endl;
    PhoneBook::displayContact(this->contact[index], true);
    std::cout << std::endl;
}

int PhoneBook::getCounter() const {
    return (this->counter);
}

bool	PhoneBook::validatePhone(const std::string &phone_number)
{
    for(std::string::size_type i = 0; i < phone_number.length(); i++)
    {
    	if (!std::isdigit(phone_number[i]) && phone_number[i] != '+')
    		return false;
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

void	PhoneBook::readInput()
{
    std::string info[5];
	std::string labels[5] = {"First Name", "Last Name", "Nickname",
		"Phone Number", "Darkest Secret"};

    std::cout << "Now, please enter the contact info" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter: " << labels[i] << std::endl;
		if (!getInput(info[i])) return;
		if (i == 3 && !PhoneBook::validatePhone(info[3]))
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
    	std::transform(command.begin(), command.end(),
    		command.begin(), ::tolower);
        if (command == "add" || command == "a")
            this->readInput();
        else if (command == "search" || command == "s")
        {
            std::cout << "|" << std::setw(10) << "Index"
            << "|" << std::setw(10) << "Firstname"
            << "|" << std::setw(10) << "Lastname"
            << "|" << std::setw(10) << "Nickname"
            << "|" << std::endl;
            this->search();
        }
        else if (command == "exit" || command == "e")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
}
