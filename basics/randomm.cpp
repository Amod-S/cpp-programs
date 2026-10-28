#include <iostream>
#include <ctime>

int main()
{
    int actual_number, guess;
    srand(time(NULL));
    actual_number = rand() % 20 + 1;
    std::cout << "Guess a number between 1 and 20: ";

    while (actual_number != guess)
    {
        std::cin >> guess;
        if (guess == actual_number)
        {
            break;
        }
        if (guess > actual_number)
        {
            std::cout << "try a smaller number\n";
        }
        else
        {
            std::cout << "try a bigger number\n";
        }
    }

    std::cout << "the number was: " << actual_number;

    return 0;
}