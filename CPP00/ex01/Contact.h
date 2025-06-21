//
// Created by Arsenii on 15.06.2025.
//

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
public:
    Contact();
    Contact(std::string info[]);
    ~Contact();

    std::string getFirstname() const;
    std::string getLastname() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif //CONTACT_H
