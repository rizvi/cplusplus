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

// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;

    // start from the root node (set current node to the root node)
    Node* currentNode = root;

    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || currentNode != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (currentNode != nullptr)
        {
            stack.push(currentNode);
            currentNode = currentNode->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            currentNode = stack.top();
            stack.pop();
            cout << currentNode->data << " ";

            currentNode = currentNode->right;
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

    inorderIterative(root);

    return 0;
}
/*
Output:
----------------------------------------------------------
E A G D F B C H
Process returned 0 (0x0)   execution time : 0.022 s
Press any key to continue.
*/

// Link: https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
