#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== CLAPTRAP TESTS =====" << std::endl;

    std::cout << "\n----- BASIC ACTIONS -----" << std::endl;
    ClapTrap a("Semenyo");

    a.attack("Thiago");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << "\n----- DAMAGE UNTIL DEATH -----" << std::endl;
    a.takeDamage(20);
    a.attack("Ballard");   // should NOT work
    a.beRepaired(5);       // should NOT work

    std::cout << "\n----- COPY CONSTRUCTOR -----" << std::endl;
    ClapTrap b(a);
    b.attack("Senesi");    // should also NOT work (copied HP = 0) a was dead → b copies HP = 0 → also dead.

    std::cout << "\n----- COPY ASSIGNMENT -----" << std::endl;
    ClapTrap c("Wilson");
    c = a;
    c.beRepaired(10);      // should NOT work

    std::cout << "\n----- INDEPENDENCE TEST -----" << std::endl;
    ClapTrap d("Guéhi");
    d.attack("Raya");

    std::cout << "\n\n===== SCAVTRAP TESTS =====" << std::endl;

    std::cout << "\n----- BASIC ACTIONS -----" << std::endl;
    ScavTrap s("Van Dijk");

    s.attack("Haaland");   // inherited from ClapTrap
    s.takeDamage(30);
    s.beRepaired(20);

    std::cout << "\n----- GUARD GATE MODE -----" << std::endl;
    s.guardGate();

    std::cout << "\n----- COPY CONSTRUCTOR -----" << std::endl;
    ScavTrap s2(s);
    s2.attack("Salah");
    s2.guardGate();

    std::cout << "\n----- COPY ASSIGNMENT -----" << std::endl;
    ScavTrap s3("Alisson");
    s3 = s;
    s3.takeDamage(100);
    s3.attack("De Bruyne"); // should NOT work

    DiamondTrap d("Diamond");
    d.attack("Enemy");
    d.takeDamage(30);
    d.beRepaired(20);
    d.whoAmI();

    return 0;
}
