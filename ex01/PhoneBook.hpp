#include "Contact.hpp"
class PhoneBook
{       // The class
    private:
        Contact _contacts[8];
    public:             // Access specifier
    //   int myNum;        // Attribute (int variable)
    //   std::string name;  // Attribute (string variable)
    //   std::string last_name;
    //   std::string nickname;
    //   std::string phone_number;
    //   std::string darkest_secret;

      void add_contact();
      void search_contact();
};