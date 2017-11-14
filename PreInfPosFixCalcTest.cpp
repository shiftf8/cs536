#include <iostream>
#include <stack>
#include <sstream>
#include <string>

static const size_t MAX_EXPRESSION_SIZE = 128;

std::string infixToPostfix(const std::string &expression);

int main()
{
    std::string input_expression;

    while (getline(std::cin, input_expression))
    {
        std::cout <<infixToPostfix(input_expression) << std::endl;
    }

    return 0;
}

std::string infixToPostfix(const std::string &expression)
{
    std::stack<char> operator_stack;
    std::string output_expression;

    std::istringstream strin(expression);
    for (std::string token; strin >> token; )
    {
        char c;
        std::istringstream wordin(token);
        
        if (token >= "A" && token <= "Z") output_expression.append(token);
        if (token == "(") operator_stack.push('(');
        if (token == ")")
        {
            while (operator_stack.top() != '(')
            {
                output_expression.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        if (token == "*")
        {
            while (operator_stack.top() != '(' || operator_stack.size() != 0)
            {
                output_expression.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push('*');
        }
        // if (token == "/")
        // {
        //     while (operator_stack.top() != '(')
        //     {
        //         output_expression.push_back(operator_stack.top());
        //         operator_stack.pop();
        //     }
        //     operator_stack.push('/');
        // }
        // if (token == "+")
        // {
        //     while (operator_stack.top() != '(' && (operator_stack.top() == '+' || operator_stack.top() == '-'))
        //     {
        //         output_expression.push_back(operator_stack.top());
        //         operator_stack.pop();
        //     }
        //     operator_stack.push('+');
        // }
        // if (token == "-")
        // {
        //     while (operator_stack.top() != '(' && (operator_stack.top() == '+' || operator_stack.top() == '-'))
        //     {
        //         output_expression.push_back(operator_stack.top());
        //         operator_stack.pop();
        //     }
        //     operator_stack.push('-');
        // }
    }
    
    return output_expression;
}