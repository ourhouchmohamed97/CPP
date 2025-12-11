#include "Zombie.hpp"

int main() {
    int N = 5;

    Zombie* horde = zombieHorde(N, "Foo");
    for(int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;

    int M = -1;

    Zombie* z = zombieHorde(M, "zombie");
    for(int i = 0; i < M; i++)
        z[i].announce();

    delete[] z;
}