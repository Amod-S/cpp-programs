
#include <iostream>

double celcius_kelvin(double temp, char unit)
{
    double result;
    if (unit == 'c')
    {
        result = temp + 273;
    }
    else
    {
        result = temp - 273;
    }
    return result;
}

double celcius_fahr(double temp, char unit)
{
    double result;
    if (unit == 'c')
    {
        result = (1.8 * temp) + 32;
    }
    else
    {
        result = (temp - 32) * 0.5556;
    }
    return result;
}

int main()
{
    double temperature, result;
    char input_unit, target_unit;

    std::cout << "Enter temperature: ";
    std::cin >> temperature;
    std::cout << "Enter unit('c', 'f' or 'k'): ";
    std::cin >> input_unit;
    std::cout << "Unit to be converted to('c', 'f' or 'k'): ";
    std::cin >> target_unit;

    if (input_unit == 'f' && target_unit == 'k')
    {
        double temp = celcius_fahr(temperature, 'f');
        result = celcius_kelvin(temp, 'c');
    }
    else if (input_unit == 'k' && target_unit == 'f')
    {
        double temp = celcius_kelvin(temperature, 'k');
        result = celcius_fahr(temp, 'c');
    }
    else
    {
        if (target_unit == 'k')
        {
            result = celcius_kelvin(temperature, 'c');
        }
        else
        {
            result = celcius_fahr(temperature, 'c');
        }
    }

    std::cout << "\nThe temperature in degree " << target_unit << " is " << result;

    return 0;
}