#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    char data;
    Node *left, *right;

    Node(char data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr)
    {
        return;
    }

    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);

    // start from the root node (set current node to the root node)
    Node* currentNode = root;

    // loop till stack is empty
    while (!stack.empty())
    {
        // if the current node exists, print it and push its right child
        // to the stack before moving to its left child
        if (currentNode != nullptr)
        {
            cout << currentNode->data << " ";

            if (currentNode->right)
            {
                stack.push(currentNode->right);
            }

            currentNode = currentNode->left;
        }
        // if the current node is null, pop a node from the stack
        // set the current node to the popped node
        else
        {
            currentNode = stack.top();
            stack.pop();
        }
    }
}


int main()
{
    /* Construct the following tree
               D
             /   \
            /     \
           A        B
          /  \     / \
         /    \   /   \
        E      G F     C
                        \
                         \
                          H
    */

    Node* root = new Node('D');
    root->left = new Node('A');
    root->right = new Node('B');
    root->left->left = new Node('E');
    root->left->right = new Node('G');
    root->right->left = new Node('F');
    root->right->right = new Node('C');
    root->right->right->right = new Node('H');

    preorderIterative(root);

    return 0;
}
/*
Output:
----------------------------------------------------------
D A E G B F C H
Process returned 0 (0x0)   execution time : 0.033 s
Press any key to continue.
*/

// Link: https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/
