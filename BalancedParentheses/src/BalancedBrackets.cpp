#include <iostream>
#include <stack>
#include <string>
#include "BalancedBrackets.h"

using namespace std;

BalancedBrackets::BalancedBrackets()
{
    //ctor
}

BalancedBrackets::~BalancedBrackets()
{
    //dtor
}

// Function to check if a given pair of parentheses are matching
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

// Function to check if the expression is balanced or not
bool isBalanced(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (s.empty() || !isMatching(s.top(), expression[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}
