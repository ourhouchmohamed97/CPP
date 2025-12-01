#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    nextContact = 0;
    countContact = 0;
}

void    add_contact(PhoneBook &phonebook) {
    Contact c;
    std::string input;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    if(std::cin.eof()) return;
    c.setFirstName(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    if(std::cin.eof()) return;
    c.setLastName(input);

    std::cout << "Nick Name: ";
    std::getline(std::cin, input);
    if(std::cin.eof())  return;
    c.setNickName(input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) return;
    c.setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    if(std::cin.eof()) return;
    c.setDarkestSecret(input);

    phonebook.addContact(c);

    std::cout << "Contact added successfully!" << std::endl;
}

void    PhoneBook::addContact(const Contact &c) {   
    contacts[nextContact] = c;
    
    if(countContact < 8)
        countContact++;
    
    nextContact = (nextContact + 1) % 8;
}

void    PhoneBook::displaySpecificContact(int index) const {
    if(index < 0 || index >= countContact) {
        std::cout << "Invalid index: out of range" << std::endl;
        return ;
    }
    const Contact &c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

void    PhoneBook::displayAllContacts() {
    if (countContact == 0) {
        std::cout << "PhoneBook is empty" << std::endl;
        return ;
    }

    std::cout << "Index" << "|"
        << "First Name" << "|"
        << "Last Name" << "|"
        << "Nick Name" << "|" << std::endl;
    
    for(int i = 0; i < countContact; i++) {
        std::cout << i << "|";
        std::cout << contacts[i].getFirstName();
        std::cout << "|";
        std::cout << contacts[i].getLastName();
        std::cout << "|";
        std::cout << contacts[i].getNickName();
        std::cout << std::endl;
    }
}

bool isNumber(const std::string s) {
    for(size_t i = 0; i < s.length(); i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}

void    search_contact(PhoneBook &phonebook) {
    phonebook.displayAllContacts();
    std::string input;
    std::cout << "Enter the index: ";
    std::getline(std::cin, input);
    if(!isNumber(input)) {
        std::cout << "Invalid input: not a number" << std::endl;
        return ;
    }
    int index = std::stoi(input);

    phonebook.displaySpecificContact(index);
}
