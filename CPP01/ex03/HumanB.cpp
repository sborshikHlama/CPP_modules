//
// Created by Arsenii on 20.06.2025.
//

#include "HumanB.h"

HumanB::HumanB(const std::string &name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
    else
        std::cout << this->name << " attacks with nothing " << std::endl;
}

