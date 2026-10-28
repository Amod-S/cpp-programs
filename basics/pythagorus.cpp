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
    std::cout << "\nThe hypotenuse is " << hypotenuse << " units long\n";

    //*************nested for loops task ******************

    int rows, columns;
    char symbol;
    std::cout << "\nEnter number of rows: ";
    std::cin >> rows;

    std::cout << "\nEnter number of columns: ";
    std::cin >> columns;

    std::cout << "\nEnter symbol to print: ";
    std::cin >> symbol;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            std::cout << symbol;
        }
        std::cout << '\n';
    }

    return 0;
}