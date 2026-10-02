/*
Assignment 6 part 2

PS: Printer Spooler (Circular Queue):
In a multi-user environment, printers often use a circular queue to manage print jobs.
Each print job is added to the queue, and the printer processes them in the order
they arrive. Once a print job is completed, it moves out of the queue, and the next
job is processed, efficiently managing the flow of print tasks. Implement the
Printer Spooler system using a circular queue without using built-in queues.
*/
/*
Expected output of Assignment No. 6 : Circular Queue

Enter maximum number of print jobs in spooler: 3
--- Printer Spooler Menu ---
1. Add Print Job
2. Process Print Job
3. Show All Print Jobs
4. Exit
Choose an option: 1
Enter print job name: Report
Print job "Report" added to the spooler.
Choose an option: 1
Enter print job name: Invoice
Print job "Invoice" added to the spooler.
Choose an option: 3
Current Print Queue: "Report" -> "Invoice"
Choose an option: 2
Processing print job: "Report"
*/

#include <iostream>
using namespace std;

bool isEmpty(int &front, int &rear)
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    return false;
}

bool isFull(int front, int rear, int max)
{
    return (rear + 1) % max == front;
}

void enqueue(string jobs[], string name, int &front, int &rear, int max)
{
    if (isFull(front, rear, max))
    {
        cout << "Queue is Full!\n";
        return;
    }
    else if (isEmpty(front, rear))
    {
        front = 0;
        rear = -1;
    }
    rear = (rear + 1) % max;
    jobs[rear] = name;
    cout << "Print job " << name << " added to the spooler.\n";
}

void dequeue(int &front, int &rear, string jobs[], int max)
{
    if (isEmpty(front, rear))
    {
        cout << "No jobs to process right now.\n";
        return;
    }
    if (rear == front)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "Processing print job: " << jobs[front];
        front = (front + 1) % max;
    }
}

void display_queue(string jobs[], int front, int rear, int max)
{
    if (isEmpty(front, rear))
    {
        cout << "No jobs to display.\n";
        return;
    }
    int i = front;
    while (true)
    {
        cout << jobs[i];
        if (i == rear)
        {
            break;
        }
        cout << " -> ";
        i = (i + 1) % max;
    }
}

int main()
{
    int max_jobs;
    int user_choice;
    int front = -1;
    int rear = -1;
    string name;

    cout << "Enter maximum number of print jobs in spooler: ";
    cin >> max_jobs;
    string jobs[max_jobs];

    do
    {
        cout << "\n--- Printer Spooler Menu ---\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Print Job\n";
        cout << "3. Show All Print Jobs\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> user_choice;

        switch (user_choice)
        {
        case 1:
            cout << "Enter job name: ";
            cin >> name;
            enqueue(jobs, name, front, rear, max_jobs);
            break;
        case 2:
            dequeue(front, rear, jobs, max_jobs);
            break;
        case 3:
            display_queue(jobs, front, rear, max_jobs);
            break;
        case 4:
            break;
        default:
            cout << "Not a valid input.\n";
            break;
        }
    } while (user_choice != 4);

    return 0;
}