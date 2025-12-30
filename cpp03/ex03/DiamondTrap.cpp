#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"),
      ScavTrap(),
      FragTrap(),
      _name("default")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;

    std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(),
      FragTrap(),
      _name(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;

    std::cout << "DiamondTrap parameterized constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
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
              << " and my ClapTrap name is " << ClapTrap::_name
              << std::endl;
}
