#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name )
    : ClapTrap(name + "_clap_name"),
    ScavTrap(name),
    FragTrap(name),
    _name(name)
{
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}


DiamondTrap::DiamondTrap( const DiamondTrap& other ) 
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      _name(other.name)
{
    std::cout << "DiamondTrap copy constructor called for" << _name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name
        << " and my ClapTrap name is " << ClapTrap::_name
        << std::endl;
}