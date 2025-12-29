#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "===== CLAPTRAP TEST =====\n";
    ClapTrap alpha("Alpha");
    alpha.attack("Target1");
    alpha.takeDamage(5);
    alpha.beRepaired(3);

    std::cout << "\n===== SCAVTRAP TEST =====\n";
    ScavTrap scout("Scout");
    scout.attack("Enemy1");
    scout.takeDamage(20);
    scout.beRepaired(10);
    scout.guardGate();

    std::cout << "\n===== FRAGTRAP TEST =====\n";
    FragTrap blaze("Blaze");
    blaze.attack("Enemy2");
    blaze.takeDamage(30);
    blaze.beRepaired(20);
    blaze.highFivesGuys();

    std::cout << "\n===== DESTRUCTION ORDER TEST =====\n";
    return 0;
}
