#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n===== SUBJECT TEST =====\n" << std::endl;
    
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    delete j; //should not create a leak 
    delete i;

    std::cout << "\n===== MY TEST =====\n" << std::endl;

    const int size = 10;
    Animal* animals[size];

    // Fill half with Dogs, half with Cats
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n===== DESTRUCTION =====\n" << std::endl;

    // Delete as Animals
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}
