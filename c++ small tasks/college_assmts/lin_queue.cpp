
/*
 * Arrival: Customers arrive at the coffee shop and stand in line.
 * Order Processing: The first customer in line gets their order taken,
 * they leave the queue, and the next customer in line moves forward.
 *
 * Implement a simple queue using an array.
 */

#include <iostream>
using namespace std;

#define MAX 4

// Check if queue is full
bool isFull(int tail)
{
    if (tail == MAX - 1)
    {
        return true;
    }
    return false;
}

// Check if queue is empty
bool isEmpty(int head)
{
    if (head == -1)
    {
        return true;
    }
    return false;
}

// Add customer to queue
void enqueue(string customers[], string name, int &head, int &tail)
{
    if (isFull(tail))
    {
        cout << "Queue is Full!" << endl;
        return;
    }

    // If queue is empty, this is the first customer
    if (head == -1)
    {
        head = 0;
        tail = 0;
    }
    else
    {
        tail++;
    }

    customers[tail] = name;

    cout << name << " joined the line.\n";
}

// Remove customer from queue
void dequeue(string customers[], int &head, int &tail)
{
    if (isEmpty(head))
    {
        cout << "Line is empty.\n";
        return;
    }

    cout << customers[head]
         << "'s order is ready. They leave the line.\n";

    head++;

    // Last customer was removed
    if (head > tail)
    {
        head = -1;
        tail = -1;
    }
}

// Display queue
void showQueue(string customers[], int head, int tail)
{
    if (isEmpty(head))
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Current line:\n";

    for (int i = head; i <= tail; i++)
    {
        cout << customers[i] << endl;
    }
}

int main()
{
    string customers[MAX];

    int user_choice;
    string customer_name;

    int head = -1;
    int tail = -1;

    do
    {
        cout << "\n\n---- Coffee Shop Queue Menu ----\n\n";
        cout << "1. Add customer to queue\n";
        cout << "2. Remove customer from queue\n";
        cout << "3. Show queue\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> user_choice;

        switch (user_choice)
        {
        case 1:
            cout << "Enter customer name: ";
            cin >> customer_name;

            enqueue(customers, customer_name, head, tail);
            break;

        case 2:
            dequeue(customers, head, tail);
            break;

        case 3:
            showQueue(customers, head, tail);
            break;

        case 4:
            cout << "Have a nice day!\n";
            break;

        default:
            cout << "Choose between options 1 and 4.\n";
        }

    } while (user_choice != 4);

    return 0;
}
