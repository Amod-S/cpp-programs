#include <iostream>
int main()
{
    // calculator
    double num1, num2, result;
    char op;

    std::cout << "\nEnter number 1: ";
    std::cin >> num1;
    std::cout << "Enter number 2: ";
    std::cin >> num2;
    std::cout << "Enter operation('+', '-', '*', '/'): ";
    std::cin >> op;

    // perform calculation
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;

        break;
    case '*':
        result = num1 * num2;

        break;
    case '/':
        result = num1 / num2;

        break;

    default:
        std::cout << "Enter one of these operators: +, -, *, /";
        break;
    }
    std::cout << "Result is: \n";
    std::cout << num1 << " " << op << " " << num2 << " = " << result;
    return 0;
}
