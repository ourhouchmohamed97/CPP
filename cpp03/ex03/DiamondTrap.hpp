#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap( std::string name );
        DiamondTrap( const DiamondTrap& other );
        DiamondTrap& operator=( const DiamondTrap& other );
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI();
};