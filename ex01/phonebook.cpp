#include <iostream>
#include <cctype>
#include <string.h>
// #include <sstream>
int main(int ac, char **av)
{
    // int i = 0;
    std::string command;
    if (ac != 1 || av[1])
    {
        std::cerr << "Argument error\n";
        return (1);
    }
    // int ii = 0;
    std::cout << "WELCOME TO THE PHONEBOOK USE IT WITH ADD, SEARCH or EXIT" << std::endl;
    while (1)
    {
        std::cout << "ENTER YOUR COMMAND" << std::endl;
        getline(std::cin, command);
        if(command.empty())
        {
            // std::cout << "ENTER YOUR COMMAND" << std::endl;
            // getline(std::cin, command);
            if (command.empty())
                continue;
        }
        if (!command.compare("ADD"))
        {
           std::string    name, last_name, nickname, phone_number, darkest_secret;
        
           std::cout << "Please put your first name:" << std::endl;
           getline(std::cin, name);
           std::cout << name << std::endl;
           std::cout << "Please put your last name:" << std::endl;
           getline(std::cin, last_name);

           std::cout << "Please put your nickname:" << std::endl;
           getline(std::cin, nickname);
          std::cout << "Please put your phone number:" << std::endl;
           getline(std::cin, phone_number);
         std::cout << "Please put your darkest secret:" << std::endl;
         getline(std::cin, darkest_secret);
          if (name.empty() || last_name.empty() || nickname.empty() || phone_number.empty()
                || darkest_secret.empty())
                std::cerr << "Some of the parameters are empty\n";
        }
         else if (!command.compare("EXIT"))
            return (std::cout << "GOODBYE\n", 0);
        else if (!command.compare("SEARCH"))
        {
            int index;
            std::cout << "INSERT ONE USER" << std::endl;
            std::cin >> index;
            // return (0);
        }

    }
    return (0);
}
