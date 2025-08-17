#include "PhoneBook.hpp"

void PhoneBook::add_contact() 
{
    Contact contact;

    std::cout << "Please put your first name:" << std::endl;
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Please put your last name:" << std::endl;
    std::string lastName;
    std::getline(std::cin, lastName);

    std::cout << "Please put your nickname:" << std::endl;
    std::string nickname;
    std::getline(std::cin, nickname);

    std::cout << "Please put your phone number:" << std::endl;
    std::string phoneNumber;
    std::getline(std::cin, phoneNumber);

    std::cout << "Please put your darkest secret:" << std::endl;
    std::string darkestSecret;
    std::getline(std::cin, darkestSecret);

    if (contact.getname().empty() || contact.getlast_name().empty() || contact.getnickname().empty() || 
        contact.getphonenumber().empty() || contact.getdarksecret().empty())
    {
        std::cerr << "Some of the parameters are empty\n";
        return ;
    }
    contact.setName(name);
    contact.setLastName(lastName);
    contact.setNickname(nickname);
    contact.setPhoneNumber(phoneNumber);
    contact.setDarkestSecret(darkestSecret);
};


void PhoneBook::search_contact()
{
    std::string input;
    int index;
    // phone.search_contact();
    std::cout << "INSERT ONE USER" << std::endl;
    if (!std::getline(std::cin, input))
        return ;
    std::stringstream ss(input);
    if (!(ss >> index) || index > 8 || index < 0)
    {
        std::cerr << "Invalid index input\n";
        // continue;
    }
}