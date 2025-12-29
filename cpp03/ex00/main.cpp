#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap alpha("Alpha");

    std::cout << "---- BASIC ACTIONS ----\n";
    alpha.attack("Target1");
    alpha.takeDamage(5);
    alpha.beRepaired(3);

    std::cout << "\n---- DAMAGE UNTIL DEATH ----\n";
    alpha.takeDamage(20);
    alpha.attack("Target2");  // should fail
    alpha.beRepaired(5);      // should fail

    std::cout << "\n---- COPY CONSTRUCTOR ----\n";
    ClapTrap beta(alpha);
    beta.attack("Target3");   // also should fail if HP=0

    std::cout << "\n---- COPY ASSIGNMENT ----\n";
    ClapTrap gamma("Gamma");
    gamma = alpha;
    gamma.beRepaired(10);     // should fail if HP=0

    std::cout << "\n---- INDEPENDENCE ----\n";
    ClapTrap delta("Delta");
    delta.attack("Target4");

    return 0;
}
