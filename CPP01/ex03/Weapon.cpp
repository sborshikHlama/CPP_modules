//
// Created by Arsenii on 20.06.2025.
//

#include "Weapon.h"

Weapon::Weapon(const std::string &type)
{
    this->type = type;
}

Weapon::~Weapon()
{

}

const std::string &Weapon::getType() const
{
    return (this->type);
}

void Weapon::setType(const std::string &value)
{
    this->type = value;
}



