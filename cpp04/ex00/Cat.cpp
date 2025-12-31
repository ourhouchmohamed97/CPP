#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat created! [default constructor]" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other) {
    std::cout << "Cat created! [copy constructor]" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned! [copy assignment]" << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat killed! [destructor]" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow 🐱" << std::endl;
}