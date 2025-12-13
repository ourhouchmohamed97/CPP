#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("Lurch");
    heapZombie->announce();

    delete heapZombie;

    randomChump("Bub");

    return 0;
}