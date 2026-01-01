#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== ABSTRACT CLASS TEST =====" << std::endl;

    // ❌ This must NOT compile (commented on purpose)
    // AAnimal animal;

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << std::endl;
    dog->makeSound();
    cat->makeSound();

    std::cout << std::endl;
    delete dog;
    delete cat;

    std::cout << "\n===== DEEP COPY TEST =====" << std::endl;

    Dog original;
    {
        Dog copy(original); // copy constructor
        std::cout << "Copy created inside scope" << std::endl;
    } // copy destroyed here

    std::cout << "Original still exists (no shared Brain)" << std::endl;

    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;

    Dog dog1;
    Dog dog2;

    dog2 = dog1; // copy assignment
    std::cout << "Assignment done successfully" << std::endl;

    std::cout << "\n===== ARRAY OF AAnimal* TEST =====" << std::endl;

    AAnimal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n===== END OF PROGRAM =====" << std::endl;
    return 0;
}

