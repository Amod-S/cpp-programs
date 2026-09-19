#include <iostream>
#include <ctime>

char getUserInput();
char getComputerInput();
void computeResults(char user, char computer);

int main()
{
    char status;
    do
    {
        std::cout << "Welcome to the game of Rock, Paper & Scissors!\n";
        std::cout << "**********************************************\n";
        srand(time(NULL));

        char user = getUserInput();
        char computer = getComputerInput();
        computeResults(user, computer);

        std::cout << "Press 'p' to play again, 'e' to exit.\n";
        std::cin >> status;
        if (status == 'e')
        {
            std::cout << "Thanks for playing!\n";
            break;
        }
    } while (true);
    return 0;
}
char getUserInput()
{
    char user;
    do
    {
        std::cout << "Enter your choice:\n";
        std::cout << "'r' for Rock\n";
        std::cout << "'p' for Paper\n";
        std::cout << "'s' for Scissors\n";
        std::cin >> user;

    } while (user != 'r' && user != 'p' && user != 's');

    std::cout << "You chose: " << user << '\n';
    return user;
}
char getComputerInput()
{
    char computer;
    char choices[3] = {'r', 'p', 's'};
    computer = choices[rand() % 3];
    std::cout << "Computer chose: " << computer << '\n';
    return computer;
}
void computeResults(char user, char computer)
{
    if (user == computer)
    {
        std::cout << "It's a tie.\n";
    }
    else if (user == 'r' && computer == 'p')
    {
        std::cout << "You lose!\n";
    }
    else if (user == 'r' && computer == 's')
    {
        std::cout << "You win!\n";
    }
    else if (user == 'p' && computer == 'r')
    {
        std::cout << "You win!\n";
    }
    else if (user == 'p' && computer == 's')
    {
        std::cout << "You lose!\n";
    }
    else if (user == 's' && computer == 'r')
    {
        std::cout << "You lose!\n";
    }
    else if (user == 's' && computer == 'p')
    {
        std::cout << "You win!\n";
    }
}