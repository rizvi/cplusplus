#include <iostream>
#include <stack>

using namespace std;

char info[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int leftChild[8] = {5,6,-1,1,-1,-1,-1,-1};
int rightChild[8] = {7,3,8,2,-1,-1,-1,-1};
int root = 0;

void preOrder()
{
    stack<int> tree;
    tree.push(-1);
    int pointer = root;

    while(pointer !=-1)
    {
        cout<< info[pointer] <<endl;
        if(rightChild[pointer] != -1)
        {
            tree.push(rightChild[pointer]);
        }

        if(leftChild[pointer] !=-1)
        {
            pointer = leftChild[pointer];
        }
        else
        {
            pointer = tree.top();
            tree.pop();
        }

    }
}

int main()
{
    preOrder();
    return 0;
}
