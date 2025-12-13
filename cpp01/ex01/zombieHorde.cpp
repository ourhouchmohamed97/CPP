#include "Zombie.hpp"

void    Zombie::setName( std::string newName ) {
    name = newName;
}

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 0) {
        std::cerr << "Error: N must be > 0" << std::endl;
        return 0;
    }
    Zombie* zombieHorde = new Zombie[N];

    for(int i = 0; i < N; i++) {
        zombieHorde[i].setName(name);
    }
    return zombieHorde;
}
