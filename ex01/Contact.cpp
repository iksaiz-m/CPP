#include "Contact.hpp"

Contact::Contact() {}


// Contact::Contact(std::string _name,
//     std::string _lastname,
//     std::string _nickname,
//     std::string _phone_number,
//     std::string _darkest_secret)
// //  _First_name(first_name),
// // _Last_name(last_name),
// // _Nickname(nickname),
// // _Phone_number(phone_number),
// // _Darkest_secret(darkest_secret)
// {}

//setters
void Contact::setName(const std::string& name)
{
    _name = name;
}

void Contact::setLastName(const std::string& lastName)
{
    _last_name = lastName;
}

void Contact::setNickname(const std::string& nickname) 
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    _phone_number = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
    _darkest_secret = darkestSecret;
}
//getters
std::string Contact::getname(void) const
{
    return (this->_name);
}

std::string Contact::getlast_name(void) const
{
    return (this->_last_name);
}
std::string Contact::getnickname(void) const
{
    return (this->_nickname);
}

std::string Contact::getphonenumber(void) const
{
    return (this->_phone_number);
}

std::string Contact::getdarksecret(void) const
{
    return (this->_darkest_secret);
}
