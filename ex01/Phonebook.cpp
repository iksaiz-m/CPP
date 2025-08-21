#include "PhoneBook.hpp"

int isvalid(std::string string)
{
    for (size_t i = 0; i < string.size(); i++)
	{
		if (string[i] == ' ' || string[i] == '	' || !isascii(string[i]))
		{
			std::cerr << "One printable word only\n";
			return	0;
		}
	}
    return (1);
}
void PhoneBook::add_contact() 
{
    Contact contact;

    std::cout << "Please put your first name:" << std::endl;
    std::string name;
    std::getline(std::cin, name);
	if (!isvalid(name))
		return ;
    std::cout << "Please put your last name:" << std::endl;
    std::string lastName;
    std::getline(std::cin, lastName);
	if (!isvalid(lastName))
		return ;
    std::cout << "Please put your nickname:" << std::endl;
    std::string nickname;
    std::getline(std::cin, nickname);
	if (!isvalid(nickname))
		return ;
    std::cout << "Please put your phone number:" << std::endl;
    std::string phoneNumber;
    std::getline(std::cin, phoneNumber);
	if (!isvalid(nickname))
		return ;
    std::cout << "Please put your darkest secret:" << std::endl;
    std::string darkestSecret;
    std::getline(std::cin, darkestSecret);

    if (name.empty() || lastName.empty() || nickname.empty() || 
        phoneNumber.empty() || darkestSecret.empty())
    {
        std::cerr << "Some of the parameters are empty\n";
        return ;
    }
    else
    {
    contact.setName(name);
    contact.setLastName(lastName);
    contact.setNickname(nickname);
    contact.setPhoneNumber(phoneNumber);
    contact.setDarkestSecret(darkestSecret);

    _contacts[_index] = contact;
    _index = (_index + 1) % 8;

    std::cout << "Contacto añadido correctamente.\n";
    }
};


void PhoneBook::search_contact()
{
    // Contact Contact;
    std::string input;
    int index;
    std::cout << "INSERT ONE USER: ";
    if (!std::getline(std::cin, input))
        return ;
    std::stringstream ss(input);
    if (!(ss >> index) || index > 8 || index < 0)
    {
        std::cerr << "Invalid index input\n";
        // continue;
    }
    else
    {
        // std::cout << index;
        std::cout << "Name: " <<_contacts[index].getname() << std::endl;
        std::cout << "Last name: " <<_contacts[index].getlast_name() << std::endl;
        std::cout << "Nickname: " <<_contacts[index].getnickname() << std::endl;
        std::cout << "Phone number: " <<_contacts[index].getphonenumber() << std::endl;
        std::cout << "Darkest secret: " <<_contacts[index].getdarksecret() << std::endl;

    }
}