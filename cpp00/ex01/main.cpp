#include "PhoneBook.hpp"


int main()
{
    Contact contactObj;

    contactObj.setFirstName("mohamed");
    contactObj.setLastName("ourhouch");
    contactObj.setNickName("eisen");
    contactObj.setPhoneNumber("06123456");
    contactObj.setDarkestSecret("nothing");

    // print
    std::cout << contactObj.getFirstName() << std::endl;
    std::cout << contactObj.getLastName() << std::endl;
    std::cout << contactObj.getNickName() << std::endl;
    std::cout << contactObj.getPhoneNumber() << std::endl;
    std::cout << contactObj.getDarkestSecret() << std::endl;
}