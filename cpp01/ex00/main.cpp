#include "Zombie.hpp"

int main() {

    std::string input;
    std::getline(std::cin, input);
    if(std::cin.eof())
        return 1;

    Zombie zombie(input);
    zombie.announce();
    return 0;    
}