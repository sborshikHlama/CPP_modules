//
// Created by Arsenii on 15.06.2025.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

# include "Contact.h"
# include <iomanip>
# define MAX_CONTACTS 8

class PhoneBook {
private:
    int	next_index;
    int	counter;
    void	displayValue(const std::string &value) const;
    void	displayContact(const Contact &contact) const;
    bool    validateNumber(const std::string &number) const;
public:
    Contact array_of_contacts[MAX_CONTACTS];
    PhoneBook();
    ~PhoneBook();
    void add(std::string info[]);
    void search() const;
    void loop();
    void read_input();
    int	getCounter() const;
};



#endif //PHONEBOOK_H
