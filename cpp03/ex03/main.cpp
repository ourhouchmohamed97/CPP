#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== DIAMONDTRAP CONSTRUCTION =====" << std::endl;
    DiamondTrap d("DI4M");

    std::cout << "\n===== ATTACK TEST =====" << std::endl;
    d.attack("enemy");          // must use ScavTrap::attack

    std::cout << "\n===== SPECIAL ABILITIES TEST =====" << std::endl;
    d.guardGate();              // from ScavTrap
    d.highFivesGuys();          // from FragTrap

    std::cout << "\n===== WHO AM I TEST =====" << std::endl;
    d.whoAmI();                 // DiamondTrap-specific

    std::cout << "\n===== CANONICAL FORM TEST =====" << std::endl;
    DiamondTrap copy(d);        // copy constructor
    DiamondTrap assign("TEMP");
    assign = d;                 // assignment operator

    copy.whoAmI();
    assign.whoAmI();

    std::cout << "\n===== DESTRUCTION ORDER =====" << std::endl;
    return 0;
}