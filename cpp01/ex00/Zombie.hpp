
#ifndef Zombie_H
#define Zombie_H

#include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
};

#endif