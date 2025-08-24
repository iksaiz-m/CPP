#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class Contact  // The class
{
    private: // Access specifier
        std::string _name;  // Attributos (strings con  _ porque son privadas)
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
    public:             // Access specifier
        //setters para añadirles el valor a los atributos
        Contact();
    //     Contact(std::string first_name,std::string last_name,
    // std::string nickname,
    // std::string phone_number,
    // std::string darkest_secret)
        void setName(const std::string& name);
        void setLastName(const std::string& lastName);
        void setNickname(const std::string& nickname);
        void setPhoneNumber(const std::string& phoneNumber);
        void setDarkestSecret(const std::string& darkestSecret);


        std::string getname() const;// el const hace que los getter se puedan compilar ya que solo tiene que leer datos
        std::string getnickname() const; // y no tienen que modificar nada
        std::string getlast_name() const;
        std::string getphonenumber() const;
        std::string getdarksecret() const;
        
};
#endif