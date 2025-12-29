#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    ScavTrap::_name = name + "_clap_name";
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;

    std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}



DiamondTrap::DiamondTrap( const DiamondTrap& other )
    : ScavTrap(other),
      FragTrap(other),
      _name(other._name)
{
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
{
    if (this != &other)
    {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);

        _name = other._name;

        FragTrap::_hitPoints = other.FragTrap::_hitPoints;
        ScavTrap::_energyPoints = other.ScavTrap::_energyPoints;
        FragTrap::_attackDamage  = other.FragTrap::_attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name
        << " and my ClapTrap name is " << ScavTrap::_name
        << std::endl;
}