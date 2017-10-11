#include <cstdio>
#include <stack>
#include <string>

using namespace std;

static const size_t MAX_EXPRESSION_SIZE = 128;

string infixToPostfix(string exp);

int main()
{
    stack<string> operator_stack;
    string expression;
    
    FILE* input_expressions;
    
    input_expressions = fopen("input.PreInfPosFixCalc.txt", "r");
    if (input_expressions == NULL) perror("Error opening file.\n");
    
    while (fgets(expression, MAX_EXPRESSION_SIZE, input_expressions) != NULL)
    {
        
    }
    
    fclose(input_expressions);

    return 0;
}

string infixToPostfix(string exp)
{
    
}