//
// Created by Arsenii on 27.07.2025.
//

#include "Zombie.h"

int main()
{
    Zombie *horde = zombieHorde( 5, "ZombieWarrior" );
    for( int i = 0; i < 5; i++ )
    {
        horde[i].announce();
    }
    delete [] horde;
    return 0;
}
