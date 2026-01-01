#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain* catBrain;
    public:
        Cat();
        Cat( const Cat& other );
        Cat& operator=(const Cat& other);
        ~Cat();
        
        void makeSound() const;
};