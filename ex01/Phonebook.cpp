#include "PhoneBook.hpp"

int isvalid(std::string string)
{
    for (size_t i = 0; i < string.size(); i++)
	{
		if (string[i] == ' ' || string[i] == '	' || !isalpha(string[i]))
		{
			std::cerr << "One printable word only\n";
			return	0;
		}
	}
    return (1);
}

int isvalid2(std::string string, int flag)
{
    int word;

    word = 0;
    if (flag == 0)
    {
        for (size_t i = 0; i < string.size(); i++)
	    {
		    if (string[i] == ' ' || string[i] == '	' || !isdigit(string[i]))
		    {
			    std::cerr << "Only one number allowed\n";
			    return	0;
		    }
	    }
    }
    else if (flag == 1)
    {
        for (size_t i = 0; i < string.size(); i++)
	    {
            if (!isalpha(string[0]))
            {
                std::cerr << "It should start with printable letters\n";
                return (0);
            }
		    if (isprint(string[i]))
                word++;
	    }
        if (word == 0)
        {
            std::cerr << "Something printable must be written\n";
            return (0);
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
	if (!isvalid2(phoneNumber, 0))
		return ;
    std::cout << "Please put your darkest secret:" << std::endl;
    std::string darkestSecret;
    std::getline(std::cin, darkestSecret);
    if (!isvalid2(darkestSecret, 1))
        return ;
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

std::string adaptstring(std::string string)
{
    std::string adaptstring;
    if (string.size() > 10)
    {
        adaptstring = string.substr(0, 10);
        adaptstring[9] = '.';
        return adaptstring;
    }
    return string;
}

void PhoneBook::search_contact()
{
    // Contact Contact;
    std::string input;
    // std::s
    int index;
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "first name" << "|";
    std::cout << std::setw(10) << std::right << "last name" << "|";
    std::cout << std::setw(10) << std::right << "nickname" << "|";
    for (int i = 0; i < 8; i++)
    {
        if (_contacts[i].getname().empty())
        {
            // std::cout << std::endl;
            break;
        }
        std::cout << std::endl;
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << adaptstring(_contacts[i].getname()) << "|";
        std::cout << std::setw(10) << std::right << adaptstring(_contacts[i].getlast_name()) << "|";
        std::cout << std::setw(10) << std::right << adaptstring(_contacts[i].getnickname()) << "|";
    }
    std::cout << std::endl;
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