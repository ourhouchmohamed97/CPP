#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "===== CLAPTRAP TESTS =====\n";

    // Basic actions
    ClapTrap alpha("Alpha");
    std::cout << "\n-- BASIC ACTIONS --\n";
    alpha.attack("Target1");
    alpha.takeDamage(5);
    alpha.beRepaired(3);

    // Damage until death
    std::cout << "\n-- DAMAGE UNTIL DEATH --\n";
    alpha.takeDamage(20);
    alpha.attack("Target2");   // should fail
    alpha.beRepaired(5);       // should fail

    // Copy constructor
    std::cout << "\n-- COPY CONSTRUCTOR --\n";
    ClapTrap beta(alpha);
    beta.attack("Target3");    // should fail

    // Copy assignment
    std::cout << "\n-- COPY ASSIGNMENT --\n";
    ClapTrap gamma("Gamma");
    gamma = alpha;
    gamma.beRepaired(10);      // should fail

    // Independence
    std::cout << "\n-- INDEPENDENCE --\n";
    ClapTrap delta("Delta");
    delta.attack("Target4");

    std::cout << "\n===== SCAVTRAP TESTS =====\n";

    // Basic actions
    ScavTrap scout("Scout");
    std::cout << "\n-- BASIC ACTIONS --\n";
    scout.attack("Enemy1");
    scout.takeDamage(30);
    scout.beRepaired(20);

    // Guard Gate mode
    std::cout << "\n-- GUARD GATE MODE --\n";
    scout.guardGate();

    // Copy constructor
    std::cout << "\n-- COPY CONSTRUCTOR --\n";
    ScavTrap sentinel(scout);
    sentinel.attack("Enemy2");
    sentinel.guardGate();

    // Copy assignment
    std::cout << "\n-- COPY ASSIGNMENT --\n";
    ScavTrap defender("Defender");
    defender = scout;
    defender.takeDamage(100);
    defender.attack("Enemy3"); // should fail

    return 0;
}
