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
    std::cout << "ENTER YOUR COMMAND" << std::endl;
    getline(std::cin, command);
    while (1)
    {
        if(command.empty())
        {
            std::cout << "ENTER YOUR COMMAND" << std::endl;
            getline(std::cin, command);
        }
        // while (command[i])
        // {
        //     command[i] = static_cast<char>(toupper(command[i]));
        //     i++;
        // }
    // else
    //     std::cout << av[1] << std::endl;
    // std::cout << av[1];
        if (!command.compare("ADD"))
        {
           std::string    name, last_name, nickname, phone_number, darkest_secret;
        
           std::cout << "Please put your first name:" << std::endl;
          // std::cin >> name;
           getline(std::cin, name);
           std::cout << name << std::endl;
           std::cout << "Please put your last name:" << std::endl;
        // std::cin >> last_name;
           getline(std::cin, last_name);

        // std::cout << last_name << std::endl;
           std::cout << "Please put your nickname:" << std::endl;
        // std::cin >> nickname;
           getline(std::cin, nickname);
        // std::cin.ignore();
          std::cout << "Please put your phone number:" << std::endl;
        // std::cin >> phone_number;
           getline(std::cin, phone_number);
        // std::cout << phone_number << std::endl;
         std::cout << "Please put your darkest secret:" << std::endl;
        // std::cin >> darkest_secret;
         getline(std::cin, darkest_secret);
        // std::cout << darkest_secret << std::endl;
          if (name.empty() || last_name.empty() || nickname.empty() || phone_number.empty()
                || darkest_secret.empty())
                std::cerr << "Some of the parameters are empty\n";
        }
         else if (!command.compare("EXIT"))
            return (0);
        else if (!command.compare("SEARCH"))
            return (0);
        else
        {
            std::cout << "ENTER YOUR COMMAND" << std::endl;
            getline(std::cin, command);
        }
    }
    // else
    //     return (std::cout << "USE ADD, EXIT or SEARCH\n", 0);
    // if (strcmp(av[1], "SEARCH"))

    // if (strcmp(av[1], "EXIT"))
    // std::cout << "xdadasdas\n";
    return (0);
}