#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    private:

    public:
        Cat();
        Cat( const Cat& other );
        Cat& operator=(const Cat& other);
        ~Cat();
        
        void makeSound() const;
};