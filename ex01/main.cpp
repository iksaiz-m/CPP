#include "PhoneBook.hpp"

std::string toupper(std::string string)
{
    for (size_t i = 0; i < string.size(); i++){
        string[i] = (string[i] >= 'a' && string[i] <= 'z') ? string[i] -= 32 : string[i];
    }
    return (string);
}
int main(int ac, char **av)
{
    std::string command;
    PhoneBook phone;
    if (ac != 1 || av[1])
    {
        std::cerr << "Argument error\n";
        return (1);
    }

    std::cout << "WELCOME TO THE PHONEBOOK USE IT WITH ADD, SEARCH or EXIT" << std::endl;
    while (1)
    {
        std::cout << "Enter your command: ";
        if (!std::getline(std::cin, command))
            return (1);
        command = toupper(command);
        if(command.empty())
                continue;
        if (command == "ADD")
        {
            phone.add_contact();
            // std::cout << phone.getname();
        }
        else if (command == "EXIT")
            return (std::cout << "GOODBYE\n", 0);
        else if (command == "SEARCH")
            phone.search_contact();
    }
    return (0);
}