/*Parenthesis Checker:
Write a program using a  stack  for push, pop, peek, and isEmpty operations.
 Write isBalanced() Function that Iterates through the input expression,
 Pushes opening brackets onto the stack. For closing brackets, it checks the top
 of the stack for a matching opening bracket. Ensures that all opening brackets are
 matched by the end of the traversal. Main Function: Accepts a string expression from
  the user. Uses isBalanced() to determine if the parentheses in the expression are
   balanced.
*/
/*Enter an expression with parentheses: (a+b)*(c+(d-e))

Expression is balanced.

Enter an expression with parentheses: (a+b)*(c+d]

Expression is NOT balanced.*/

#include <iostream>
using namespace std;

bool isEmpty(int top)
{
    return top < 0;
}

void push(char stack[], char element, int &top)
{
    top++;
    stack[top] = element;
}

char pop(char stack[], int &top)
{
    char temp = stack[top];
    top--;
    return temp;
}

bool isBalanced(string expression)
{
    int top = -1;
    char stack[10];
    for (int i = 0; i < expression.size(); i++)
    {
        char current = expression[i];

        if (current == '(' || current == '{' || current == '[')
        {
            push(stack, current, top);
        }
        else if (current == ')' || current == '}' || current == ']')
        {
            if (!isEmpty(top))
            {
                char upper = pop(stack, top);
                if (!(upper == '(' && current == ')' ||
                      upper == '{' && current == '}' ||
                      upper == '[' && current == ']'))
                {
                    return false;
                }
            }
        }
    }
    if (!isEmpty(top))
        return false;
    return true;
}

int main()
{
    string user_input;
    cout << "Enter an expression with parentheses: ";
    cin >> user_input;
    if (isBalanced(user_input))
    {
        cout << "Expression is balanced" << endl;
    }
    else
    {
        cout << "Expression is not balanced" << endl;
    }
    return 0;
}