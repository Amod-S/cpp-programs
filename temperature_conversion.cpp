// converts temperature from degree fahrenheit to degree celcius or vice versa.
#include <iostream>

double c2f(double temperature)
{
    double f = (1.8 * temperature) + 32;
    return f;
}
double f2c(double temperature)
{
    double c = (temperature - 32) * 0.5556;
    return c;
}

int main()
{

    double celcius, fahrenheit, result, temp;
    char input_form;

    std::cout << "Enter temperature: ";
    std::cin >> temp;

    std::cout << "\nIs the given temperature in degree Celcius or degree Fahrenheit?('c'/'f'): ";
    std::cin >> input_form;

    switch (input_form)
    {
    case 'c':
        result = c2f(temp);
        break;
    case 'f':
        result = f2c(temp);
        break;
    default:
        std::cout << "Enter 'c' or 'f'.";
    }

    // display results
    std::cout << result;

    return 0;
}