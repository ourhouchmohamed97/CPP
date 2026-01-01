#pragma once

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal( std::string const &type );
        AAnimal( const AAnimal& other );
        AAnimal& operator=(const AAnimal& other );
        virtual ~AAnimal();

        std::string const &getType( void )const;
        virtual void makeSound() const = 0;
};