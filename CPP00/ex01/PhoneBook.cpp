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

void	PhoneBook::displayValue(const std::string &value) const {
    std::string	formatted;

    if (value.length() > 10)
        std::cout << "|" << std::setw(10) << value.substr(0, 9) + ".";
    else
        std::cout << "|" << std::setw(10) << value;
}

void PhoneBook::add(std::string info[])
{
    array_of_contacts[this->next_index] = Contact(info);
    if (this->counter < MAX_CONTACTS)
        this->counter++;
    this->next_index = (this->next_index + 1) % MAX_CONTACTS;
}

void	PhoneBook::displayContact(const Contact &contact) const {
    std::cout << "First Name: " << contact.getFirstname() << std::endl;
    std::cout << "Last Name: " << contact.getLastname() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void	PhoneBook::search() const {
    int counter;
    int	index;

    counter = this->getCounter();
    for (int i = 0; i < counter; i++)
    {
        std::cout << "|" << std::setw(10) << i;
        this->displayValue(this->array_of_contacts[i].getFirstname());
        this->displayValue(this->array_of_contacts[i].getLastname());
        this->displayValue(this->array_of_contacts[i].getNickname());
        std::cout << "|" << std::endl;
    }
    std::cout << "Enter the contact index" << std::endl;
    std::cin >> index;
    if (std::cin.fail() || index > this->getCounter())
    {
        std::cout << "Invalid Index!\n" << std::endl;
        std::cin.clear();
        return ;
    }
    std::cout << std::endl;
    this->displayContact(this->array_of_contacts[index]);
    std::cout << std::endl;
}

int PhoneBook::getCounter() const {
    return (this->counter);
}

bool	PhoneBook::validateNumber(const std::string &number) const{
    for(std::string::size_type i = 0; i < number.length(); i++)
    {
        if (number[i] == ' ')
            i++;
        else if (number[i] < '0' || number[i] > '9')
            return 0;
    }
    return (true);
}

void	PhoneBook::read_input()
{
    std::string info[5];
    std::cout << "Now, please enter the contact info" << std::endl;
    std::cout << "Enter first name" << std::endl;
    std::getline(std::cin, info[0]);
    std::cout << "Enter lastname" << std::endl;
    std::getline(std::cin, info[1]);
    std::cout << "Enter nickname" << std::endl;
    std::getline(std::cin, info[2]);
    std::cout << "Enter phone number" << std::endl;
    std::getline(std::cin, info[3]);
    while (!this->validateNumber(info[3]))
    {
        std::cout << "Please, enter a valid phone number" << std::endl;
        std::getline(std::cin, info[3]);
    }
    std::cout << "Enter darkest secret" << std::endl;
    std::getline(std::cin, info[4]);
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
            this->read_input();
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
