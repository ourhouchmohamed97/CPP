#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
    dogBrain = new Brain();
    std::cout << "Dog created! [default constructor]" << std::endl;
}

Dog::Dog( const Dog& other ) : AAnimal(other) {
    dogBrain = new Brain(*other.dogBrain);
    std::cout << "Dog copied! [copy constructor]" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned! [copy assignment]" << std::endl;
    if(this != &other) {
        AAnimal::operator=(other);
        delete dogBrain;
        dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

Dog::~Dog() {
    delete dogBrain;
    std::cout << "Dog killed! [destructor]" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof 🐶" << std::endl;
}