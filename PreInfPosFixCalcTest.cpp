#include <iostream>
#include <stack>
#include <string>

using namespace std;

static const size_t MAX_EXPRESSION_SIZE = 128;

string infixToPostfix(string exp);

int main()
{
    stack<char> operator_stack;
    string expression;
    char c;
    
    FILE* input_expressions;
    
    input_expressions = fopen("input.PreInfPosFixCalc.txt", "r");
    if (input_expressions == NULL) perror("Error opening file.\n");
    
    // fscanf(input_expressions, "%c", &c);
    // cout << c << endl;
    // expression.push_back(c);
    // cout << expression << endl;
    
    while (fscanf(input_expressions, "%c", &c) != EOF)
    {
        if (c >= 'A' && c <= 'Z') expression.push_back(c);
        if (c == '(') operator_stack.push(c);
        if (c == ')')
        {
            while (operator_stack.top() != '(')
            {
                expression.push_back(operator_stack.pop());
            }
            operator_stack.pop();
        }
        if (c == '*' || c == '/' || c == '+' || c == '-')
        {
            
        }
    }
    
    fclose(input_expressions);

    return 0;
}

string infixToPostfix(string exp)
{
    
}