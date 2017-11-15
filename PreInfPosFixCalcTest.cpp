#include <iostream>
#include <stack>
#include <sstream>
#include <string>

std::string infixToPostfix(const std::string &expression);
bool isEqualOrHigherPrecedence(const char top_of_stack, const char input);
double evaluatePostfix(const std::string &post_fix_expression);
std::string postfixToPrefix(const std::string &expression);

int main()
{
    std::string infix_expression;

    while (getline(std::cin, infix_expression))
    {
        std::string post_fix_expression;
        std::string pre_fix_expression;
        
        post_fix_expression = infixToPostfix(infix_expression);
        std::cout <<post_fix_expression <<std::endl;
        
        pre_fix_expression = postfixToPrefix(post_fix_expression);
        std::cout <<pre_fix_expression <<std::endl;
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
            if (!operator_stack.empty())
            {
                while (operator_stack.top() != '(' && isEqualOrHigherPrecedence(operator_stack.top(), '*'))
                {
                    output_expression.push_back(operator_stack.top());
                    operator_stack.pop();
                }
            }
            operator_stack.push('*');
        }
        if (token == "/")
        {
            if (!operator_stack.empty())
            {
                while (operator_stack.top() != '(' && isEqualOrHigherPrecedence(operator_stack.top(), '/'))
                {
                    output_expression.push_back(operator_stack.top());
                    operator_stack.pop();
                }
            }
            operator_stack.push('/');
        }
        if (token == "+")
        {
            if (!operator_stack.empty())
            {
                while (operator_stack.top() != '(' && isEqualOrHigherPrecedence(operator_stack.top(), '+'))
                {
                    output_expression.push_back(operator_stack.top());
                    operator_stack.pop();
                }
            }
            operator_stack.push('+');
        }
        if (token == "-")
        {
            if (!operator_stack.empty())
            {
                while (operator_stack.top() != '(' && isEqualOrHigherPrecedence(operator_stack.top(), '-'))
                {
                    output_expression.push_back(operator_stack.top());
                    operator_stack.pop();
                }
            }
            operator_stack.push('-');
        }
    }
    
    while (!operator_stack.empty())
    {
        output_expression.push_back(operator_stack.top());
        operator_stack.pop();
    }
    
    return output_expression;
}
bool isEqualOrHigherPrecedence(const char top_of_stack, const char input)
{
    if (top_of_stack == '*' && (input == '*' || input == '/' || input == '+' || input == '-')) return true; //Easier to read and more explicit, to test each input possibility.
    if (top_of_stack == '/' && (input == '/' || input == '+' || input == '-')) return true;
    if (top_of_stack == '+' && (input == '+' || input == '-')) return true;
    if (top_of_stack == '-' && (input == '-')) return true;
    
    return false;
}
double evaluatePostfix(const std::string &post_fix_expression)
{
    
}
std::string postfixToPrefix(const std::string &expression)
{
    std::stack<std::string> S;
    std::string ch;

    for (int i = 0; i < expression.length(); ++i)
    {
        ch = expression[i];
        if (ch >= "A" && ch <= "Z") S.push(ch);
        if (ch == "*" || ch == "/" || ch == "+" || ch == "-")
        {
            std::string x = S.top();
            S.pop();
            std::string y =  S.top();
            S.pop();
            S.push(ch + x + y);
        }
    }
    
    return S.top();
}