#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

std::string infixToPostfix(const std::string expression);
bool isEqualOrHigherPrecedence(const std::string top_of_stack, const std::string current_char);
std::string stackOperator(std::stack<std::string>& operation_stack, std::string& return_expression, const std::string operator_ch);
double evaluatePostfix(const std::string post_fix_expression);
double binaryEvaluation(std::stack<double>& operand_stack, const std::string operator_ch);
std::string postfixToPrefix(const std::string expression);

int main()
{
    std::string infix_expression;
    int column_width = 16;

    std::cout <<std::left <<std::setw(column_width) <<"infix"
        <<std::left <<std::setw(column_width) <<"prefix"
        <<std::left <<std::setw(column_width) <<"postfix"
        <<std::left <<std::setw(column_width) <<"value" <<"\n\n";

    while (getline(std::cin, infix_expression))
    {
        std::string post_fix_expression;
        std::string pre_fix_expression;
        double post_fix_evaluation;
        
        post_fix_expression = infixToPostfix(infix_expression);
        pre_fix_expression = postfixToPrefix(post_fix_expression);
        post_fix_evaluation = evaluatePostfix(post_fix_expression);
        
        std::string::iterator new_end = std::remove_if(infix_expression.begin(), infix_expression.end(), isspace);
        
        std::cout <<std::left <<std::setw(column_width) <<std::string(infix_expression.begin(), new_end)
            <<std::left <<std::setw(column_width) <<pre_fix_expression
            <<std::left <<std::setw(column_width) <<post_fix_expression
            <<std::left <<std::setw(column_width) <<post_fix_evaluation <<std::endl;
    }

    return 0;
}

std::string infixToPostfix(const std::string expression)
{
    std::stack<std::string> operator_stack;
    std::string output_expression;
    std::string ch;

    for (int i = 0; i < expression.length(); ++i)
    {
        ch = expression[i];
        if (ch >= "A" && ch <= "Z") output_expression.append(ch);
        if (ch == "(") operator_stack.push(ch);
        if (ch == ")")
        {
            while (operator_stack.top() != "(")
            {
                output_expression.append(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        if (ch == "*" || ch == "/" || ch == "+" || ch == "-") output_expression = stackOperator(operator_stack, output_expression, ch);
    }
    
    while (!operator_stack.empty())
    {
        output_expression.append(operator_stack.top());
        operator_stack.pop();
    }
    
    return output_expression;
}
bool isEqualOrHigherPrecedence(const std::string top_of_stack, const std::string current_char)
{
     //Easier to read and more explicit, to test each current_char possibility.
    if (top_of_stack == "*" && (current_char == "*" || current_char == "/" || current_char == "+" || current_char == "-")) return true;
    if (top_of_stack == "/" && (current_char == "/" || current_char == "+" || current_char == "-")) return true;
    if (top_of_stack == "+" && (current_char == "+" || current_char == "-")) return true;
    if (top_of_stack == "-" && (current_char == "-")) return true;
    
    return false;
}
std::string stackOperator(std::stack<std::string>& operation_stack, std::string& return_expression, const std::string operator_ch)
{
    while (!operation_stack.empty() && operation_stack.top() != "(" && isEqualOrHigherPrecedence(operation_stack.top(), operator_ch))
    {
        return_expression.append(operation_stack.top());
        operation_stack.pop();
    }
    operation_stack.push(operator_ch);
    
    return return_expression;
}
double evaluatePostfix(const std::string post_fix_expression)
{
    double variable_values[] = {2.0, 3.0, 4.0, 5.0, 6.0}; //Hard coded variable values in array. e.g. A, B, C = 1.0, 2.0, 3.0
    std::stack<double> S;
    std::string ch;

    for (int i = 0; i < post_fix_expression.length(); ++i)
    {
        ch = post_fix_expression[i];

        if (ch == "A") S.push(variable_values[0]);
        if (ch == "B") S.push(variable_values[1]);
        if (ch == "C") S.push(variable_values[2]);
        if (ch == "D") S.push(variable_values[3]);
        if (ch == "E") S.push(variable_values[4]);
        
        if (ch == "*" || ch == "/" || ch == "+" || ch == "-") S.push(binaryEvaluation(S, ch));
    }

    return S.top();
}
double binaryEvaluation(std::stack<double>& operand_stack, const std::string operator_ch)
{
    double A;
    double B;
    double retVal;

    A = operand_stack.top();
    operand_stack.pop();
    B = operand_stack.top();
    operand_stack.pop();
    
    if (operator_ch == "*") retVal = B * A;
    if (operator_ch == "/") retVal = B / A; //This assumes the denominator isn't zero.
    if (operator_ch == "+") retVal = B + A;
    if (operator_ch == "-") retVal = B - A;
    
    return retVal;
}
std::string postfixToPrefix(const std::string expression)
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
            S.push(ch + y + x);
        }
    }
    
    return S.top();
}