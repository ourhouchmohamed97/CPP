#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "===== DIAMONDTRAP CONSTRUCTION =====\n";
    DiamondTrap apex("Apex");

    std::cout << "\n===== ATTACK TEST =====\n";
    apex.attack("Enemy1");        // uses ScavTrap::attack

    std::cout << "\n===== SPECIAL ABILITIES TEST =====\n";
    apex.guardGate();             // from ScavTrap
    apex.highFivesGuys();         // from FragTrap

    std::cout << "\n===== WHO AM I TEST =====\n";
    apex.whoAmI();                // DiamondTrap-specific

    std::cout << "\n===== CANONICAL FORM TEST =====\n";
    DiamondTrap beta(apex);       // copy constructor
    DiamondTrap gamma("Temp");
    gamma = apex;                 // assignment operator

    beta.whoAmI();
    gamma.whoAmI();

    std::cout << "\n===== DESTRUCTION ORDER =====\n";
    return 0;
}
