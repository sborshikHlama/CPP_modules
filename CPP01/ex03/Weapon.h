//
// Created by Arsenii on 20.06.2025.
//

#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>


class Weapon {
private:
    std::string type;
public:
    Weapon(const std::string &type);
    ~Weapon();
    const std::string& getType() const;
    void setType(const std::string &value);
};



#endif //WEAPON_H
