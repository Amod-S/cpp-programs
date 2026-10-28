#include <iostream>

namespace example
{
    int x = 10;
}

int main()
{

    // single line comment

    /*
    Multi-line comment
    this program file includes basic c++ operations and information.
    */

    // standard output
    std::cout << "My name is Amod." << std::endl;
    std::cout << "abc." << '\n';

    // variables and datatypes
    int age = 19;        // integers
    bool student = true; // boolean values: true or false
    double cost = 23.99; // numbers with decimals
    char grade = 'B';    // single entities like letters, symbols
    std::string name = "Amod";

    // constant variables
    const double PI = 3.142;
    /* variables whose values shouldn't be changed
    are declared as constants.*/

    // namespace
    // prevents name conflicts.
    int x = 9;
    std::cout << x << '\n';  // local variable x=9
    std::cout << example::x; // variable from namespace 'example' = 10

    // taking input from user
    int user_input;

    std::cout << "\nType an integer: ";
    std::cin >> user_input; // cout: character output; stores in user_input variable.
    std::cout << "Your integer: " << user_input;

    /*now to accepet white spaces inside the input string, things change.df
      we need to use getline function to accept white spaces.
    */
    /*
    std::string full_name;
    std::cout << "\nEnter your full name: ";
    std::getline(std::cin, full_name);
    std::cout << "Your name: " << full_name;*/

    /*but if we are using getline after a previously used only cin,
     there is a \n in the input buffer after cin, and the getline takes that input buffer(\n) and so, jumps on new line.
     so we use std::ws to elimininate any newline characters or white spaces, like so: */
    std::string full_name;
    std::cout << "\nEnter your full name: ";
    std::getline(std::cin >> std::ws, full_name);
    std::cout << "Your name: " << full_name;

    return 0;
}