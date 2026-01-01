#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal( std::string const &type );
        WrongAnimal( const WrongAnimal& other );
        WrongAnimal& operator=(const WrongAnimal& other );
        ~WrongAnimal();

        void makeSound() const;
};