/*7. Printer Spooler (Circular Queue)
Application: In a multi-user environment, printers often use a circular queue
to manage print jobs. Each print job is added to the queue, and the printer
processes them in the order they arrive. Once a print job is completed, it
moves out of the queue, and the next job is processed, efficiently managing
the flow of print tasks.
- Implement the Printer Spooler system using a circular queue without using
built-in queues.
- Draw the graphical representation of a circular queue using an array and linked list.
- Justify that “Circular queue is more efficient than simple queue”.
- What are the advantages of a circular queue over a simple queue?
- What are the applications of circular queues?*/

#include <iostream>
using namespace std;
#define MAX 4

bool isFull(string arr[], int head, int tail)
{
    return ((tail + 1) % MAX) == head;
}

bool isEmpty(int tail)
{
    return tail == -1;
}

void enqueue(string arr[], int &head, int &tail, string name)
{
    if (head == -1)
    {
        head = 0;
        tail = 0;
        arr[head] = name;
        cout << name << " job was added to the queue." << endl;
        return;
    }
    if (isFull(arr, head, tail))
    {
        cout << "Queue is full." << endl;
        return;
    }
    tail = (tail + 1) % MAX;
    arr[tail] = name;
    cout << name << " job was added to the queue." << endl;
}

void deque(string arr[], int &head, int &tail)
{
    if (isEmpty(tail))
    {
        cout << "No jobs to process" << endl;
        return;
    }
    if (head == tail)
    {
        cout << arr[head] << " job is processed successfully." << endl;
        head = -1;
        tail = -1;
        return;
    }
    cout << arr[head] << " job is processed successfully." << endl;
    head = (head + 1) % MAX;
}

void display(string arr[], int head, int tail)
{
    if (isEmpty(tail))
    {
        cout << "No jobs to display." << endl;
        return;
    }
    int i = head;
    while (true)
    {
        cout << arr[i] << '\t';
        if (i == tail)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
}

int main()
{

    int tail = -1;
    int head = -1;
    string jobs[MAX];
    int user_choice;
    string jobName;
    do
    {
        cout << "Enter your choice" << endl;
        cout << "1. Add a job" << endl;
        cout << "2. Process a job" << endl;
        cout << "3. Display jobs" << endl;
        cout << "4. Exit" << endl;
        cin >> user_choice;

        switch (user_choice)
        {
        case 1:
            cout << "Enter job name: " << endl;
            cin >> jobName;
            enqueue(jobs, head, tail, jobName);
            break;
        case 2:
            deque(jobs, head, tail);
            break;
        case 3:
            display(jobs, head, tail);
            break;
        case 4:
            continue;
        default:
            cout << "Enter a valid input." << endl;
            break;
        }

    } while (user_choice != 4);

    return 0;
}