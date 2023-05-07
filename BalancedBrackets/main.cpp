#include <iostream>
#include <stack>
#include <string>

using namespace std;


// Class for Balanced Parentheses
class BalancedBrackets
{

private:
// Check if a given pair of parentheses are matching
    bool isMatching(char opening, char closing)
    {
        if (opening == '(' && closing == ')')
        {
            return true;
        }
        else if (opening == '{' && closing == '}')
        {
            return true;
        }
        else if (opening == '[' && closing == ']')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
// Check if the expression is balanced or not
    bool isBalanced(string expression)
    {
        stack<char> stk;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            {
                stk.push(expression[i]);
            }
            else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
            {
                if (stk.empty() || !isMatching(stk.top(), expression[i]))
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};


//Create object of BalancedBrackets class and call isBalanced function
int main()
{
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;
    BalancedBrackets pb;
    if (pb.isBalanced(expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
