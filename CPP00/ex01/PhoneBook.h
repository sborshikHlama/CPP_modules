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
    static void	displayValue(const std::string &value, const bool full) ;
    static void	displayContact(const Contact &contact, const bool full) ;
	static bool	getInput(std::string &dst);
    static bool validateNumber(const std::string &number) ;
	static bool	promptInput(std::string labels, std::string &dst);
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
