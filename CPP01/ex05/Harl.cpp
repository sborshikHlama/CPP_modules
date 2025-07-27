//
// Created by Arsenii on 23.06.2025.
//

#include "Harl.h"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::error()
{
    std::cout <<  "I think I deserve to have some extra bacon for free. "
    << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::warning()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    typedef void (Harl::*func)();
    std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "WARNING"};
    func list[5] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::warning };
    for (int i = 0; i < 5; i++)
    {
        if (levels[i] == level)
        {
            (this->*list[i])();
            return;
        }
    }
}


