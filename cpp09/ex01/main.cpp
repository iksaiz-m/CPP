#include "RPN.hpp"

// Infix: 1 + 2 -> RPN: 1 2 +
// Infix: 1 + 2 * 3 -> RPN: 1 2 3 * + (evaluates 2*3 first) 
// Infix: (1 + 2) * 3 -> RPN: 1 2 + 3 * (evaluates 1+2 first)
// Push numbers to the stack then when an operator apear use the top two and push the result back
int main(int ac, char **av)
{
    if(ac !=2)
        return (std::cerr << "Error: there should be arguments." << std::endl, 1);
    std::string equation = av[1];
    // RPN rpn();
    // MutantStack<int> rpn();
    MutantStack<int> mstack;
    size_t pos = 0;
    int number;
    int result;
    while (pos < equation.length())
    {
        if (isalpha(equation[pos]))
            return (std::cerr << "Error: there should not be any character" << std:: endl, 1);
        if (isdigit(equation[pos]))
        {
            if (!isspace(equation[pos + 1]))
                return (std::cerr << "Error: should be one space between numbers and operators should be last" << std:: endl, 1);
            number = std::atoi(equation.substr(pos, 1 ).c_str());
            // std::cout << number << std::endl;
            mstack.push(number);
        }
        else if (equation[pos] == '/')
        {
            if (mstack.size() < 2)
                return (std::cerr << "Error: there should be at least two numbers to divide" << std:: endl, 1);
            else
            {
                number = mstack.top();
                mstack.pop();
                result = mstack.top();
                mstack.pop();
                if (number == 0)
                    return (std::cerr << "Error: you cant divide by 0" << std:: endl, 1);
                result = result / number;
                mstack.push(result);
                
            }
        }
        else if (equation[pos] == '*')
        {
            if (mstack.size() < 2)
            {
                std::cout << mstack.size() << std::endl;
                return (std::cerr << "Error: there should be at least two numbers to muliply" << std:: endl, 1);
            }
            else
            {
                 number = mstack.top();
                mstack.pop();
                result = mstack.top();
                mstack.pop();
                result = result * number;
                mstack.push(result);
            }
        }
        else if (equation[pos] == '+')
        {
            if (mstack.size() < 2)
                return (std::cerr << "Error: there should be at least two numbers to sum" << std:: endl, 1);
            else
            {
                 number = mstack.top();
                mstack.pop();
                result = mstack.top();
                mstack.pop();
                result = result + number;
                mstack.push(result);
            }
        }
        else if (equation[pos] == '-')
        {
            if (mstack.size() < 2)
                return (std::cerr << "Error: there should be at least two numbers to rest" << std:: endl, 1);
            else
            {
                 number = mstack.top();
                mstack.pop();
                result = mstack.top();
                mstack.pop();
                result = result - number;
                mstack.push(result);
            }
        }
        else if (!isspace(equation[pos]))
            return (std::cerr << "Error: there should not be anything other than numbers and operators" << std:: endl, 1);
        // if (!isspace(equation[pos]))
        //     std::cout << pos << "no es un espacio" << std::endl;
        // std::cout << equation[pos];
        pos++;
    }
    
    // std::cout << '96' << std::endl;
    std::cout << mstack.top() << std::endl;
    // mstack.push(5);
}
