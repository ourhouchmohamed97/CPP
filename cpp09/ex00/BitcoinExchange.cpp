#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDB( const std::string& DB ) {
    std::ifstream file(DB.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");
    std::string line;
    std::getline(file, line); // skip header 'date | value'

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string rate;

        std::getline(ss, date, ',');
        std::getline(ss, rate);

        _database[date] = std::atof(rate.c_str());
    }
}

static std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

void BitcoinExchange::processInput(const std::string& input)
{
    std::ifstream file(input.c_str());

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        size_t pipePos = line.find('|');

        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string value = trim(line.substr(pipePos + 1));

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        try
        {
            if (!isValidValue(value))
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }

            double val = std::strtod(value.c_str(), NULL);
            double rate = getExchangeRate(date);

            std::cout << date << " => "
                      << val << " = "
                      << val * rate << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}


bool BitcoinExchange::isValidDate( const std::string& date ) const {
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue( const std::string& value ) const {
    char *end;
    double val = std::strtod(value.c_str(), &end);

    if (*end != '\0')
        return false;

    if (val < 0)
        throw std::runtime_error("Error: not a positive number.");

    if (val > 1000)
        throw std::runtime_error("Error: too large a number.");

    return true;
}

double BitcoinExchange::getExchangeRate( const std::string& date ) const {
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

    if (it == _database.end())
        --it;
    else if (it->first != date) {
        if (it == _database.begin())
            throw std::runtime_error("Error: no earlier date available.");
        --it;
    }
    return it->second;
}