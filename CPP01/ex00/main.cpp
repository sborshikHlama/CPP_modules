#include <iostream>
#include "Zombie.h"

int main()
{
    Zombie *z = newZombie( "Zombie" );
    z->announce();
    delete z;
    randomChump("ZombieBob");
    Zombie *horde = zombieHorde( 5, "ZombieWarrior" );
    for( int i = 0; i < 5; i++ )
    {
        horde[i].announce();
    }
    delete [] horde;
    return 0;
}
