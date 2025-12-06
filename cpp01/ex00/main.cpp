#include "Zombie.hpp"

int main() {

    std::string input;
    std::getline(std::cin, input);

    Zombie zombie(input);
    zombie.announce();

    Zombie* z = newZombie("Lurch");
    z->announce();

    randomChump("Bub");
    
    delete z;

    return 0;
}