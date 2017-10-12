#include <iostream>
#include <stack>
#include <string>

using namespace std;

static const size_t MAX_EXPRESSION_SIZE = 128;

string infixToPostfix(string expression);

int main()
{
    stack<char> operator_stack;
    string expression;
    char c;
    
    FILE* input_expressions;
    
    input_expressions = fopen("input.PreInfPosFixCalc.txt", "r");
    if (input_expressions == NULL) perror("Error opening file.\n");
    
    while (fscanf(input_expressions, "%c", &c) != EOF)
    {
        if (c >= 'A' && c <= 'Z') expression.push_back(c);
        if (c == '(') operator_stack.push(c);
        if (c == ')')
        {
            while (operator_stack.top() != '(')
            {
                expression.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        if (c == '*' || c == '/' || c == '+' || c == '-')
        {
            // while ((operator_stack.top() != '(') || (!operator_stack.empty()))
            // {
            //     // //Split conditional for easier reading
            //     // if ((c == '*' || c == '/') && (operator_stack.top() == '+' || operator_stack.top() == '-')) //Check if current operator is of higher precedence
            //     // {
            //     //     expression.push_back(operator_stack.top());
            //     //     operator_stack.pop();
            //     // }
            //     // else if (c == operator_stack.top()) //Check if current operator is of equal precedence
            //     // {
            //     //     expression.push_back(operator_stack.top());
            //     //     operator_stack.pop();
            //     // }
            // }
            operator_stack.push(c);
        }
    }

    fclose(input_expressions);

    return 0;
}

string infixToPostfix(string expression)
{
    
}