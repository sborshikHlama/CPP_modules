//
// Created by Arsenii on 20.06.2025.
//

#include "HumanA.h"

HumanA::HumanA(const std::string &name, Weapon &weapon): weapon(weapon)
{
    this->name = name;
    this->weapon = weapon;
}

HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their" << this->weapon.getType() << std::endl;
}

