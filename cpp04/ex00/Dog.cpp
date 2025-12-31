#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog created! [default constructor]" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other) {
    std::cout << "Dog created! [copy constructor]" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned! [copy assignment]" << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog killed! [destructor]" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof 🐶" << std::endl;
}