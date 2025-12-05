#include "PhoneBook.hpp"

int main() {
    PhoneBook   phonebook;
    std::string command;

    while(true)
    {
        std::cout << "Enter command {ADD, SEARCH, EXIT}: ";
        std::getline(std::cin, command);
        if(std::cin.eof())
            break;
        if(command == "ADD")
            add_contact(phonebook);
        else if(command == "SEARCH")
            search_contact(phonebook);
        else if(command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}