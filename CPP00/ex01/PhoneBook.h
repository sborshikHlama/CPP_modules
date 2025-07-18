//
// Created by Arsenii on 15.06.2025.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

# include "Contact.h"
# include <sstream>
# include <iomanip>
# define MAX_CONTACTS 8

class PhoneBook {
private:
    int	next_index;
    int	counter;
    static void	displayContact(const Contact &contact, bool full) ;
	static bool	getInput(std::string &dst);
    static bool validatePhone(const std::string &phone_number) ;
public:
    Contact contact[MAX_CONTACTS];
    PhoneBook();
    ~PhoneBook();
    void add(std::string info[]);
    void search() const;
    void loop();
    void readInput();
    int	getCounter() const;
};



#endif //PHONEBOOK_H
