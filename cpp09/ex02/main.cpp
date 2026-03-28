#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe p;
        p.parseInput(ac, av);
        p.sort();
        p.display();
    } catch(std::exception& e) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    return 0;
}