#pragma once

#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double> _database;
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void loadDB( const std::string& DB );
        void processInput( const std::string& input );
};