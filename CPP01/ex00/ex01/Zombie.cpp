//
// Created by Arsenii on 16.06.2025.
//

#include "Zombie.h"
Zombie::Zombie() {}

Zombie::Zombie(const std::string &name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Destroying: " << this->name << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}
