#pragma once

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _database;

    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void loadDB( const std::string& DB );
        void processInput( const std::string& input );

        bool isValidDate( const std::string& date ) const;
        bool isValidValue( const std::string& value ) const;
        double getExchangeRate( const std::string& date ) const;
};