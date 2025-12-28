#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== CLAPTRAP TEST =====" << std::endl;
    ClapTrap clap("CL4P");
    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n===== SCAVTRAP TEST =====" << std::endl;
    ScavTrap scav("SC4V");
    scav.attack("intruder");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n===== FRAGTRAP TEST =====" << std::endl;
    FragTrap frag("FR4G");
    frag.attack("enemy");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n===== DESTRUCTION ORDER TEST =====" << std::endl;
    return 0;
}
