#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
    
    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc;
        btc.loadDB("data.csv");
        btc.processInput(av[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}