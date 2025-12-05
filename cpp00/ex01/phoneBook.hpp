
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>  // for std::setw

class Contact {
    // fields
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    // default construct
    public:
        Contact();
    // setters
    void    setFirstName(const std::string &value);
    void    setLastName(const std::string &value);
    void    setNickName(const std::string &value);
    void    setPhoneNumber(const std::string &value);
    void    setDarkestSecret(const std::string &value);
    // getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     nextContact;
        int     countContact;

    public:
        PhoneBook();
        void    addContact(const Contact &c);
        void    displayAllContacts();
        void    displaySpecificContact(int index) const;
};

// functions prototype 

void    add_contact(PhoneBook &phonebook);
void    search_contact(PhoneBook &phonebook);

#endif