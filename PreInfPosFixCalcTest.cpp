#include <iostream>
#include <stack>
#include <string>

static const size_t MAX_EXPRESSION_SIZE = 128;

std::string infixToPostfix(std::string expression);

int main()
{
    std::stack<char> operator_stack;
    std::string input_expression;
    std::string output_expression;

    while (getline(std::cin, input_expression))
    {
        std::cout <<infixToPostfix(input_expression) << std::endl;
    }

    return 0;
}

std::string infixToPostfix(std::string expression)
{
    while ()
    {
        break;
    }
    return "x";
}