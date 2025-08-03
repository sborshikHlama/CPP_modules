//
// Created by Arsenii on 23.06.2025.
//

#include "Harl.h"

void Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-"
              << "triple-pickle-special-ketchup burger. I really do!\n";
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You "
              << "didn’t put enough bacon in my burger! If you did, I wouldn’t"
              << " be asking for more!\n";
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout <<  "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years, whereas you started working here"
              << " just last month.\n";
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager nowa.\n";
    std::cout << std::endl;
}

LOG_LEVEL Harl::stringToLog(std::string level)
{
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARN") return WARNING;
    if (level == "ERROR") return ERROR;
    return (FAILED_STATUS);
}


void Harl::complain(char *level)
{
    LOG_LEVEL log = Harl::stringToLog(level);

    switch (log)
    {
        case FAILED_STATUS:
            std::cout << level << ": FAILED STATUS\n";
            break;
        case DEBUG:
            Harl::debug();
        case INFO:
            Harl::info();
        case WARNING:
            Harl::warning();
        case ERROR:
            Harl::error();
            break;
    }
}
