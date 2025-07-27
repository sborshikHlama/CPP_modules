//
// Created by Arsenii on 20.06.2025.
//

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
    Weapon &weapon;
    std::string name;
public:
    HumanA(const std::string &name, Weapon &weapon);
    ~HumanA();
    void attack() const;
};



#endif //HUMANA_H
