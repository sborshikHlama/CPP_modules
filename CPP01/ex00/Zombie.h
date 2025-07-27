//
// Created by Arsenii on 16.06.2025.
//

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
private:
    std::string name;
public:
    Zombie();
    Zombie(const std::string &name);
    void setName(const std::string &name);
    ~Zombie();
    void    announce();
};

Zombie *newZombie( std::string name );
void    randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif //ZOMBIE_H
