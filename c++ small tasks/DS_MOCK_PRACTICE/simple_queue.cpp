/*6. Coffee Shop Line (Simple Queue)
Arrival: Customers arrive at the coffee shop and stand in line.

Order Processing: The first customer in line gets their order taken,
 and the barista starts making the coffee.

Serving: Once the first customer is served, they leave the queue, and
 the next customer in line moves forward to be served.
- Write a program to implement a simple queue.
- Differentiate between simple queue and circular queue.
- Also draw the graphical representation of a simple queue using an array
and linked list.
*/
#include <iostream>
using namespace std;
#define MAX 10

bool isFull(int tail)
{
    return tail == MAX - 1;
}

bool isEmpty(int head)
{
    return head == -1;
}

void enqueue(int &head, int &tail, string name, string customer[])
{
    if (head == -1)
    {
        head = tail = 0;
        customer[tail] = name;
        cout << name << " was added to the queue." << endl;
        return;
    }
    if (isFull(tail))
    {
        cout << "Queue is full!" << endl;
        return;
    }
    customer[++tail] = name;
    cout << name << " was added to the queue." << endl;
}

void deque(int &head, int &tail, string customer[])
{
    if (isEmpty(head))
    {
        cout << "Queue is already empty." << endl;
        return;
    }
    if (head == tail)
    {
        cout << customer[head] << "'s order is ready. They leave the queue." << endl;
        head = tail = -1;
        return;
    }
    cout << customer[head++] << "'s order is ready. They leave the queue." << endl;
}

void display(int head, int tail, string customer[])
{
    if (isEmpty(head))
    {
        cout << "There is no one in the line" << endl;
        return;
    }
    cout << "Current line: " << endl;
    if (head == tail)
    {
        cout << customer[tail] << endl;
        return;
    }
    for (int i = head; i <= tail; i++)
    {
        cout << customer[i] << '\t';
    }
    cout << endl;
}

int main()
{
    int user_choice;
    string name;
    int tail = -1;
    int head = -1;
    string customers[MAX];

    do
    {
        cout << "Enter your choice:" << endl;
        cout << "1. Add to queue." << endl;
        cout << "2. Process the order." << endl;
        cout << "3. Display the current queue" << endl;
        cout << "4. Exit" << endl;

        cin >> user_choice;

        switch (user_choice)
        {
        case 1:
            cout << "Enter customer name." << endl;
            cin >> name;
            enqueue(head, tail, name, customers);
            break;
        case 2:
            deque(head, tail, customers);
            break;
        case 3:
            display(head, tail, customers);
            break;
        case 4:
            cout << "Bye" << endl;
            break;
        default:
            cout << "Enter a valid choice." << endl;
            break;
        }

    } while (user_choice != 4);

    return 0;
}