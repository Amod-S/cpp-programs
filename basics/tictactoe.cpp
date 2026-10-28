#include <iostream>
using namespace std;

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    int row = -1;
    int column = -1;
    char player = 'X';
    int currentPlayer;

    for (int i = 0; i < 9; i++)
    {
        // print game board
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        // get user input and assign it
        cout << "Current player: " << player << endl;
        cout << "Enter the row number and column number: ";
        cin >> row >> column;
        board[row][column] = player;
        player = (player == 'X') ? 'O' : 'X';
    }
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
    return 0;
}