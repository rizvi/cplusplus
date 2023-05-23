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

// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }

    // create an empty stack and push the root node
    stack<Node*> firstStack;
    firstStack.push(root);

    // create another stack to store postorder traversal
    stack<char> out;

    // loop till stack is empty
    while (!firstStack.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* currentNode = firstStack.top();
        firstStack.pop();

        out.push(currentNode->data);

        // push the left and right child of the popped node into the stack
        if (currentNode->left) {
            firstStack.push(currentNode->left);
        }

        if (currentNode->right) {
            firstStack.push(currentNode->right);
        }
    }

    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
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

    postorderIterative(root);

    return 0;
}
/*
Output:
----------------------------------------------------------
E G A F H C B D
Process returned 0 (0x0)   execution time : 0.026 s
Press any key to continue.
*/

// Link: https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/
