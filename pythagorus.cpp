#include <iostream>
#include <math.h>

int main()
{
    double base, height, hypotenuse;

    std::cout << "This program calculates the hypotenuse of a right angled triangle.";

    // take input values
    std::cout << "\nEnter length of base: ";
    std::cin >> base;
    std::cout << "Enter length of height: ";
    std::cin >> height;

    // calculate hypotenuse by pythagorus theorum.
    hypotenuse = sqrt(pow(base, 2) + pow(height, 2));

    // display results
    std::cout << "\nThe hypotenuse is " << hypotenuse << " units long";

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