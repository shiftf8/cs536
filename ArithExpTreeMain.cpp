#include <iostream>
#include <stack>
#include <string>
#include "BTNode.cpp"

using namespace std;

BTNode* makeArithmeticExpressionTree(string postfix);
void postOrderPrint(BTNode* root);

int main()
{
    string post_fix_expression;
    BTNode* root;
    
    while (getline(cin, post_fix_expression))
    {
        cout <<post_fix_expression <<endl;
        root = makeArithmeticExpressionTree(post_fix_expression);
        postOrderPrint(root);
        cout <<endl;
    }

    return 0;
}

BTNode* makeArithmeticExpressionTree(string postfix)
{
    stack<BTNode*> bt_node_ptrs;
    char c;
    
    for (int i = 0; i < postfix.length(); ++i)
    {
        BTNode* tmp;
        c = postfix[i];
        
        if (c >= 'A' && c <= 'Z')
        {
            tmp = new BTNode(c);
            bt_node_ptrs.push(tmp);
        }
        if (c == '*' || c == '/' || c == '+' || c == '-')
        {
            BTNode* p1;
            BTNode* p2;
            
            p1 = bt_node_ptrs.top();
            bt_node_ptrs.pop();
            p2 = bt_node_ptrs.top();
            bt_node_ptrs.pop();
            
            tmp = new BTNode(c, p2, p1);
            bt_node_ptrs.push(tmp);
        }
    }
    
    return bt_node_ptrs.empty() ? nullptr : bt_node_ptrs.top();
}
void postOrderPrint(BTNode* root)
{
    if (root == nullptr) return;
    
    postOrderPrint(root->getLeft());
    postOrderPrint(root->getRight());
    cout <<root->getItem();
}