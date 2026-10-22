/*5. Organizing Cards in a Hand (Insertion Sort)
Application: When playing card games, players often use an approach similar to
insertion sort to organize their cards. They pick one card at a time and insert
it into the correct position in their hand, maintaining a sorted sequence.

Write a program that demonstrates how to organize (sort) cards in a hand using
insertion sort.
- Discuss the applications of insertion sort.
- Also write the advantages of the same.*/

#include <iostream>
using namespace std;

int main()
{

    int deck[13];
    // take input of cards
    cout << "Enter cards: " << endl;
    for (int i = 0; i < 13; i++)
    {
        cin >> deck[i];
    }
    // display cards before sorting
    cout << endl
         << "Before sorting" << endl;
    for (int i = 0; i < 13; i++)
    {
        cout << deck[i] << '\t';
    }
    cout << endl;
    // insertion sort
    for (int i = 1; i < 13; i++)
    {
        int temp = deck[i];
        int j = i - 1;
        while (j >= 0 && deck[j] > temp)
        {
            deck[j + 1] = deck[j];
            j--;
        }
        deck[j + 1] = temp;
    }
    // display cards after sorting
    cout << endl
         << "After sorting" << endl;
    for (int i = 0; i < 13; i++)
    {
        cout << deck[i] << '\t';
    }

    return 0;
}