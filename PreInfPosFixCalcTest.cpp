#include <iostream>
#include <stack>
#include <string>

static const size_t MAX_EXPRESSION_SIZE = 128;

std::string infixToPostfix(std::string expression);
bool isOperand(char c);

int main()
{
    std::string input_expression;

    while (getline(std::cin, input_expression))
    {
        std::cout <<infixToPostfix(input_expression) << std::endl;
    }

    return 0;
}

std::string infixToPostfix(std::string expression)
{
    std::stack<char> operator_stack;
    std::string output_expression;
    char c;
    
    while (sscanf(expression, "%c", c)) //CANNOT use sscanf. Need to use string functions?
    {
        if (isOperand(c)) output_expression.push_back();
    }
    
    return output_expression;
}
bool isOperand(char c)
{
    if (c != '*' && c != '/' && c != '+' && c != '-') return true;
    return false;
}