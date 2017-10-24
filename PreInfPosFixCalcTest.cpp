#include <iostream>
#include <stack>
#include <string>

using namespace std;

static const size_t MAX_EXPRESSION_SIZE = 128;

string infixToPostfix(string expression);
bool isLowerPrecedence(char current_operator, char top_of_operator_stack);

int main()
{
    stack<char> operator_stack;
    string output_expression;
    char c;


    FILE* file_input;
    
    file_input = fopen("input.PreInfPosFixCalc.txt", "r");
    if (file_input == NULL) perror("Error opening file.\n");
    
    while ((c = fgetc(file_input)) != EOF)
    {
        if (c >= 'A' && c <= 'Z') output_expression.push_back(c);
        if (c == '(') operator_stack.push(c);
        if (c == ')')
        {
            while (operator_stack.top() != '(')
            {
                output_expression.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        if (c == '*' || c == '/' || c == '+' || c == '-')
        {
            while (!operator_stack.empty())
            {
                if (operator_stack.top() == '(')
                {
                    operator_stack.pop();
                    break;
                }
                if (!isLowerPrecedence(c, operator_stack.top()))
                {
                    output_expression.push_back(operator_stack.top());
                    operator_stack.pop();
                }
            }
            operator_stack.push(c);
        }
        if (c == '\n')
        {
            cout << output_expression << endl;
            output_expression.clear();
            while(!operator_stack.empty()) operator_stack.pop();
        }
    }

    fclose(file_input);

    return 0;
}

string infixToPostfix(string expression)
{
    
}
bool isLowerPrecedence(char current_operator, char top_of_operator_stack)
{
    if (current_operator == top_of_operator_stack) return false;
    if ((current_operator == '*' || current_operator == '/') && (top_of_operator_stack == '+' || top_of_operator_stack == '-')) return false;
    return true;
}
