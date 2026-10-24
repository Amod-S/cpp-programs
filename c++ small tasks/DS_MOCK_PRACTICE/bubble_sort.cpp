/*
4. Game Development (Bubble Sort)
Write a game development program that implements the Bubble Sort algorithm.
The program will simulate a simple game where the player can input a set of
numbers, and the numbers will be sorted using Bubble Sort to simulate a
"level-up" scenario where the player's scores are sorted in ascending order.
- Discuss the disadvantages of bubble sort.
- Also justify that “bubble sort is not an efficient sorting technique.”*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[])
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int scores[10];
    cout << "Enter 10 scores" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> scores[i];
    }

    cout << "Scores before sorting:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << scores[i] << '\t';
    }

    bubbleSort(scores);
    cout << "\nScores after sorting:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << scores[i] << '\t';
    }

    return 0;
}