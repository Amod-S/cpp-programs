/*2. Parenthesis Checker
Write a program using a stack for push, pop, peek, and isEmpty operations.
Write isBalanced() function that iterates through the input expression, pushes
opening brackets onto the stack. For closing brackets, it checks the top of the stack
for a matching opening bracket. Ensures that all opening brackets are matched by the end
of the traversal.

Main Function: Accepts a string expression from the user. Uses isBalanced() to determine if the
parentheses in the expression are balanced.*/

#include <iostream>
using namespace std;
#define MAX 10

bool isFull(int top)
{
    return top == MAX - 1;
}

bool isEmpty(int top)
{
    return top == -1;
}

void push(char arr[], int &top, char value)
{
    if (isFull(top))
    {
        cout << "Stack is full!" << endl;
        return;
    }
    top++;
    arr[top] = value;
}

int pop(char arr[], int &top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    return arr[top--];
}

int peek(int arr[], int &top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    return arr[top];
}

void display(int arr[], int &top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << endl;
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

bool isBalanced(string expr)
{
    char myStack[MAX];
    char current;
    int top = -1;
    for (int i = 0; i < expr.length(); i++)
    {
        current = expr[i];
        if (current == '(' || current == '[' || current == '{')
        {
            push(myStack, top, current);
        }
        else if (current == ')' || current == ']' || current == '}')
        {
            char match = pop(myStack, top);
            if (match == '(' && current == ')' ||
                match == '[' && current == ']' ||
                match == '{' && current == '}')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (!isEmpty(top))
    {
        return false;
    }
    return true;
}

int main()
{

    string expression;
    cout << "Enter expression:\n";
    cin >> expression;
    if (expression.length() > MAX)
    {
        cout << "Expression cannot have more than 10 characters";
    }
    else if (isBalanced(expression))
    {
        cout << "Expression is balanced" << endl;
    }
    else if (!isBalanced(expression))
    {
        cout << "Expression is not balanced" << endl;
    }
    else
    {
        cout << "wrong";
    }

    return 0;
}