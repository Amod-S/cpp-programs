/*
There are different ways to represent a mathematical  expression
1st- The regular one, known as infix form: (A+B)
2nd- Prefix or polish notation: +AB
3rd- Postfix or reverse polish notation: AB+

This program takes infix input, gives the user a choice to get it's polish or
reverse polish form. Stack is the main data structure used here.
change of plans- this code only converts from infix to postfix, because that itself is boss level.XD
*/
#include <iostream>
using namespace std;
#define MAX 100

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

string reverseIt(string input)
{
    string res = "";
    for (int i = input.length() - 1; i >= 0; i--)
    {
        res += input[i];
    }
    return res;
}

bool precedence(char current, char top)
{
    /*will return true if its okay to push(ie. current has higher precedence than top), false otherwise*/
    if ((top == '^' && current != '^') || ((top == '*' || top == '/') && (current != '*' || current != '/')))
    {
        return true;
    }
    return false;
}

string postfix(string infix)
{
    string result = "";
    char current;
    char arr[infix.length()];
    char stack[infix.length()];
    int top = -1;
    for (int i = 0; i < infix.length(); i++)
    {
        current = arr[i];
        if (current == '(' || current == '[' || current == '{')
        {
            push(arr, top, current);
        }
        else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '^')
        {
            if (precedence(current, stack[top]))
            {
                push(stack, top, current);
            }
            else
            {
                while (!precedence(current, stack[top]))
                {
                    result += pop(stack, top);
                }
            }
        }
        else if (current == ')' || current == ']' || current == '}')
        {
            while (!(current == ')' && stack[top] == '(' ||
                     current == '}' && stack[top] == '{' ||
                     current == ']' && stack[top] == '['))
            {
                result += pop(stack, top);
            }
        }
        else
        {
            result += current;
        }
    }
    while (!isEmpty(top))
    {
        result += stack[top];
    }
    return result;
}

int main()
{

    int user_choice;
    string infix_input;
    cout << "Enter the expression: ";
    cin >> infix_input;

    string postfix_result = postfix(infix_input);
    cout << postfix_result << endl;

    return 0;
}