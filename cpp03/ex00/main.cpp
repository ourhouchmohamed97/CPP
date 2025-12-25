#include "ClapTrap.hpp"

int main()
{
    std::cout << "----- BASIC ACTIONS -----" << std::endl;
    ClapTrap a("Semenyo");

    a.attack("Thiago");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << "\n----- DAMAGE UNTIL DEATH -----" << std::endl;
    a.takeDamage(20);
    a.attack("Ballard");
    a.beRepaired(5);

    std::cout << "\n----- COPY CONSTRUCTOR -----" << std::endl;
    ClapTrap b(a);
    b.attack("Senesi"); // should also NOT work (copied HP = 0)

    std::cout << "\n----- COPY ASSIGNMENT -----" << std::endl;
    ClapTrap c("Wilson");
    c = a;
    c.beRepaired(10);

    std::cout << "\n----- INDEPENDENCE TEST -----" << std::endl;
    ClapTrap d("Guéhi");
    d.attack("Raya");

    return 0;
}
