#pragma once

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal( std::string const &type );
        Animal( const Animal& other );
        Animal& operator=(const Animal& other );
        ~Animal(); // i think this must be virtual

        void makeSound();
};