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

        return 0;
}