#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << " [ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << " [ INFO ]" << std::endl;
    std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << " [ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << " [ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{

    // if (!level.compare("debug") || !level.compare("info") || !level.compare("warning") || !level.compare("error"))
//     {
//         return (Harl::info());
//     }

    // if (level == "debug") debug();
    // else if (level == "info") info();
    // else if (level == "warning") warning();
    // else if (level == "error") error();


    // Array with all the levels from 0 debug to 3 error
    const std::string levels[] = {"debug", "info", "warning", "error"};
    // Pointers for each function where
    // 1: Harl::* makes it search inside Harl class
    // 2: [] because its an array
    // 3: () because we call functions in this case without arguments
    void (Harl::*functions[])() = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i]) // compares string with the levels in array
        {
            // (this->*functions[i])(); // 
            return (this->*functions[i])(); // we can return the void functions here because complain returns void too
        }
    }
    std::cout << "Invalid level: " << level << std::endl;
}