#include <iostream>
#include <string>
#include "BalancedBrackets.h"

using namespace std;

int main()
{
    string expression;

    cout << "Enter the expression: ";
    cin >> expression;

    if (isBalanced(expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
    return 0;
}
