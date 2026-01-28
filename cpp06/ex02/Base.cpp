#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base * generate(void) {
    int random = rand() % 3;
    if (random == 0) return new A;
    if (random == 1) return new B;
    return new C;
}

void identify(Base* p) {
    dynamic_cast<A *>(p);
    dynamic_cast<B *>(p);
    dynamic_cast<C *>(p);
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch(...) {}

    try {
        B& b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch(...) {}

    try {
        C& c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch(...) {}
}