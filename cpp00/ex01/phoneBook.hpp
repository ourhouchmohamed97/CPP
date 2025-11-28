
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>

class PhoneBook {
    public:
        PhoneBook();
    private:
        // Contact contacts[8];
        int     nextContact;
        int     countContact;
};

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

#endif