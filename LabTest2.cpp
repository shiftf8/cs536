#include <iostream>

using namespace std;

static int max_data = -1; //Ugly global hack

struct Node
{
    int data;
    Node* left;
    Node* right;
};

bool equal(Node* r1, Node* r2);
int find_max(Node* r);

int main()
{
    Node* root1 = new Node;
    Node* r1_2 = new Node;
    Node* r1_3 = new Node;
    Node* r1_4 = new Node;
    Node* r1_5 = new Node;
    Node* r1_6 = new Node;
    Node* r1_7 = new Node;
    
    root1->data = 1, root1->left = r1_2, root1->right = r1_3;
    r1_2->data = 2, r1_2->left = r1_4, r1_2->right = r1_7;
    r1_3->data = 3, r1_3->left = r1_6, r1_3->right = r1_5;
    r1_4->data = 4, r1_4->left = nullptr, r1_4->right = nullptr;
    r1_5->data = 5, r1_5->left = nullptr, r1_5->right = nullptr;
    r1_6->data = 6, r1_6->left = nullptr, r1_6->right = nullptr;
    r1_7->data = 7, r1_7->left = nullptr, r1_7->right = nullptr;
    
    Node* root2 = new Node;
    Node* r2_2 = new Node;
    Node* r2_3 = new Node;
    Node* r2_4 = new Node;
    Node* r2_5 = new Node;
    Node* r2_6 = new Node;
    root2->data = 1, root2->left = r2_2, root2->right = r2_3;
    r2_2->data = 9, r2_2->left = nullptr, r2_2->right = r2_4;
    r2_3->data = 3, r2_3->left = r2_5, r2_3->right = r2_6;
    r2_4->data = 5, r2_4->left = nullptr, r2_4->right = nullptr;
    r2_5->data = 6, r2_5->left = nullptr, r2_5->right = nullptr;
    r2_6->data = 5, r2_6->left = nullptr, r2_6->right = nullptr;
    
    cout <<"equal(nullptr, nullptr)\t\t\t" <<equal(nullptr, nullptr) <<endl
        <<"equal(nullptr, root1)\t\t\t" <<equal(nullptr, root1) <<endl
        <<"equal(root1, root1)\t\t\t" <<equal(root1, root1) <<endl
        <<"equal(root1, root2)\t\t\t" <<equal(root1, root2) <<endl
        <<"equal(root1, root2->left)\t\t" <<equal(root1, root2->left) <<endl
        <<"equal(root1->right, root2->right)\t" <<equal(root1->right, root2->right) <<endl
        <<"findMax(nullPtr)\t\t\t" <<find_max(nullptr) <<endl;
    max_data = -1;
    cout <<"findMax(root1)\t\t\t\t" <<find_max(root1) <<endl;
    max_data = -1;
    cout <<"findMax(root2)\t\t\t\t" <<find_max(root2) <<endl;
    
    return 0;
} //main

bool equal(Node* r1, Node* r2)
{
    if (r1 == nullptr && r2 == nullptr) return true;
    if (r1 != nullptr && r2 != nullptr)
    {
        return (r1->data == r2->data && equal(r1->left, r2->left) && equal(r1->right, r2->right));
    }
    return false;
}
int find_max(Node* r) //Total hack. Used global static var.
{
    if (r == nullptr) return max_data;
    if (max_data < r->data) max_data = r->data;
    find_max(r->left);
    find_max(r->right);
    return max_data;
}