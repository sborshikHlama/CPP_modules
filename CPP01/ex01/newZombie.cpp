//
// Created by Arsenii on 16.06.2025.
//

#include "Zombie.h"

Zombie *newZombie( std::string name )
{
    return new Zombie(name);
}
