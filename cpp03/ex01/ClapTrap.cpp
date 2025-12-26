#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.

void ClapTrap::attack( const std::string& target )
{
    if(_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name
                 << " can't attack (no HP or energy left)" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage( unsigned int amount )
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;

    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage! (HP: "
              << _hitPoints << ")" << std::endl;
}
void ClapTrap::beRepaired( unsigned int amount )
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " can't be repaired (no HP or energy left)" << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name
              << " repairs itself for " << amount
              << " hit points! (HP: "
              << _hitPoints << ")" << std::endl;
}