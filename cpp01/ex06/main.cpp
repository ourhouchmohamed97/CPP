#include "Harl.hpp"

int main(int ac, char **av) {
    if(ac != 2) {
        std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
        return 1;
    }
    Harl h;
    std::string level = av[1];
    h.complain(av[1]);

    return 0;
}