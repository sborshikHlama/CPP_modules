//
// Created by Arsenii on 23.06.2025.
//

#include "Harl.h"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-"
              << "triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You "
              << "didn’t put enough bacon in my burger! If you did, I wouldn’t"
              << " be asking for more!\n";
}

void Harl::error()
{
    std::cout <<  "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years, whereas you started working here"
              << " just last month.\n";
}

void Harl::warning()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    typedef void (Harl::*func)();

    std::pair<std::string, func> const pair_array[] = {
        std::make_pair("DEBUG", &Harl::debug),
        std::make_pair("INFO", &Harl::info),
        std::make_pair("WARNING", &Harl::warning),
        std::make_pair("ERROR", &Harl::error),
    };

    for (int i = 0; i < 4; i++)
    {
        if (pair_array[i].first == level)
        {
            (this->*pair_array[i].second)();
            return;
        }
    }
}


