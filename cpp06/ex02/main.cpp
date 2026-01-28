#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}
