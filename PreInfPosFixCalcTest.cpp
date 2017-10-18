#include <iostream>
#include <stack>
#include <string>

using namespace std;

static const size_t MAX_EXPRESSION_SIZE = 128;

string infixToPostfix(string expression);
bool isEqualOrHigherPrecedence(char current_operator, char top_of_operator_stack);

int main()
{
    stack<char> operator_stack;
    string expression_string;
    char expression[MAX_EXPRESSION_SIZE] = {0};
    
    FILE* input_expressions;
    
    input_expressions = fopen("input.PreInfPosFixCalc.txt", "r");
    if (input_expressions == NULL) perror("Error opening file.\n");
    
    while (fgets(expression, MAX_EXPRESSION_SIZE - 1, input_expressions))
    {
        char c;
        int i = 0;
        
        while ((c = expression[i]) != '\n')
        {
            if (c >= 'A' && c <= 'Z') expression_string.push_back(c);
            if (c == '(') operator_stack.push(c);
            if (c == ')')
            {
                while (operator_stack.top() != '(')
                {
                    expression_string.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                operator_stack.pop();
            }
            if (c == '*' || c == '/' || c == '+' || c == '-')
            {
                if (!operator_stack.empty())
                {
                    while (1)
                    {
                        expression_string.push_back(operator_stack.top());
                        operator_stack.pop();
                        break;
                    }
                    operator_stack.push(c);
                }
                else operator_stack.push(c);
            }
            i++;
        }
        
        cout << expression_string << endl;
        expression_string.clear();
        while(!operator_stack.empty()) operator_stack.pop();
    }

    fclose(input_expressions);

    return 0;
}

string infixToPostfix(string expression)
{
    
}
bool isEqualOrHigherPrecedence(char current_operator, char top_of_operator_stack)
{
    if (current_operator == top_of_operator_stack) return true;
    if ((current_operator == '*' || current_operator == '/') && (top_of_operator_stack == '+' || top_of_operator_stack == '-')) return true;
    return false;
}
