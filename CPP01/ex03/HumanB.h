//
// Created by Arsenii on 20.06.2025.
//

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
public:
    Weapon *weapon;
    std::string name;
    HumanB(const std::string &name);
    ~HumanB();
    void setWeapon(Weapon &weapon);
    void attack() const;
};



#endif //HUMANB_H
