#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}


// 1️⃣ Zombie::Zombie(std::string name)
// This is the constructor definition.
// Zombie:: → means the constructor belongs to the Zombie class
// Zombie(...) → this is the constructor itself
// (std::string name) → it takes one argument, also called name
// So this part means:
// 👉 “Create a Zombie and receive a string called name as input.”
// 2️⃣ :
// This colon starts the member initializer list.
// This list allows you to initialize member variables BEFORE the constructor body runs.
// 3️⃣ name(name)
// This is the initialization itself.
// It means:
// The first name → the class’s private attribute
// The second name → the parameter passed to the constructor
// So:
// 👉 “Initialize the attribute name with the value of the parameter name.”


Zombie::~Zombie() {
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}