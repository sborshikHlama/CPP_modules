#include <iostream>
#include "PhoneBook.h"

int	main()
{
    PhoneBook	phoneBook;

    std::string inputs0[5] = {"somename", "aevstign", "vojta", "25352443", "seru"};
    std::string inputs1[5] = {"blabla", "asdasd", "tutu", "231231", "lolo"};
    std::string inputs2[5] = {"bsdad", "aevstign", "vo", "4535435345", "seru"};
    std::string inputs3[5] = {"tutu", "toto", "tutu", "54353453", "lolo"};
    std::string inputs4[5] = {"bob", "aevstign", "va", "345345345", "seru"};
    std::string inputs5[5] = {"jim", "toto", "tutu", "53453453", "lolo"};
    std::string inputs6[5] = {"nobody", "polo", "nono", "34534535", "seru"};
    std::string inputs7[5] = {"bimo", "bobo", "koko", "3453453", "fofo"};
	phoneBook.add(inputs0);
    phoneBook.add(inputs1);
    phoneBook.add(inputs2);
    phoneBook.add(inputs3);
    phoneBook.add(inputs4);
    phoneBook.add(inputs5);
    phoneBook.add(inputs6);
    phoneBook.add(inputs7);
    phoneBook.loop();
    return (0);
}
