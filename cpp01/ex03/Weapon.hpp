
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;

    public:
        Weapon( const std::string& type );
        const std::string& getType() const; //the reference is fast because you pass only the address. No copying, no duplication, no performance cost.
        void setType( const std::string& newType );
};

#endif