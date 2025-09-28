#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :AForm::AForm("ShrubberyCreationForm", 145, 137, target)//, _target(target) // default constructor
{
    std::cout << " ShrubberyCreationForm Default constructor called" << std::endl;
    // _target = target;
    // this->_signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)//, _target(other._target)// copy constructor
{
        std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        // cant do the others because they are a const variable they cant change
        // this->_signed = other._signed;
        AForm::operator=(other);
    }
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
    return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
    std::string tree = this->getTarget();
    std::ofstream filetree(tree.append("_shrubbery").c_str()); // creates new file with the apropiate name
    if (!filetree.is_open())
    {
         std::cout << "Error: couldn't create output file" << std::endl; // if it cant create it then return an error
        return ;
    }
    filetree << "       _-_\n";
    filetree << "    /~~   ~~\\\n";
    filetree << " /~~         ~~\\\n";
    filetree << "{               }\n";
    filetree << " \\  _-     -_  /\n";
    filetree << "   ~  \\\\ //  ~\n";
    filetree << "_- -   | | _- _\n";
    filetree << "  _ -  | |   -_\n";
    filetree << "      // \\\\\n";
    filetree.close();                  // closes the file after writting a beautiful tree in it
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& ShrubberyCreationForm) {
    os << "ShrubberyCreationForm " << ShrubberyCreationForm.getName()
       << " [signed: " << std::boolalpha << ShrubberyCreationForm.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << ShrubberyCreationForm.getSGrade()
       << ", grade to execute: " << ShrubberyCreationForm.getEGrade()
       << "]";
    return os;
}