#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    catBrain = new Brain();
    std::cout << "Cat created! [default constructor]" << std::endl;
}

Cat::Cat( const Cat& other ) : AAnimal(other) {
    catBrain = new Brain(*other.catBrain); // Deep copy
    std::cout << "Cat copied! [copy constructor]" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned! [copy assignment]" << std::endl;
    if(this != &other) {
        AAnimal::operator=(other);
        delete catBrain;
        catBrain = new Brain(*other.catBrain); // Deep copy
    }
    return *this;
}

Cat::~Cat() {
    delete catBrain;
    std::cout << "Cat killed! [destructor]" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow 🐱" << std::endl;
}