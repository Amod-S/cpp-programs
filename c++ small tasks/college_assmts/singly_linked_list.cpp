/*
PROBLEM STATEMENT:
 Simple Task Scheduler:
 Write a program that implements a simple task scheduler using a singly linked list.
 Each node in the linked list represents a task with its priority and execution time.
 Tasks are scheduled based on their priority, with higher priority tasks being
 executed first.
*/

/*
Expected Output of Assignment No. 4:
Enter number of tasks to schedule: 3
Task 1 Name: T1
Priority (higher = more important): 2
Execution Time (ms): 300
Task 2 Name: T2
Priority (higher = more important): 5
Execution Time (ms): 150
Task 3 Name: T3
Priority (higher = more important): 3
Execution Time (ms): 200
Scheduled Tasks (Highest Priority First):
Task: T2, Priority: 5, Execution Time: 150 ms
Task: T3, Priority: 3, Execution Time: 200 ms
Task: T1, Priority: 2, Execution Time: 300 ms
Executing Tasks:
Executing Task 'T2' [Priority: 5] for 150 ms...
Executing Task 'T3' [Priority: 3] for 200 ms...
Executing Task 'T1' [Priority: 2] for 300 ms
All tasks executed.
*/
#include <iostream>
using namespace std;

struct Node
{
    string name;
    int priority;
    int time;
    Node *next;
};

void insert_node(Node *head, Node *newnode)
{
    if (head->next == NULL)
    {
        head->next = newnode;
        return;
    }
    if (newnode->priority > head->next->priority)
    {
        newnode->next = head->next;
        head->next = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL && newnode->priority < temp->next->priority)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

int main()
{
    int no_of_tasks;
    cout << "Enter number of tasks to schedule: ";
    cin >> no_of_tasks;

    Node *head = new Node();
    head->next = NULL;

    for (int i = 0; i < no_of_tasks; i++)
    {
        Node *newnode = new Node();
        newnode->next = NULL;
        cout << "Enter task " << i + 1 << " name: ";
        cin >> newnode->name;
        cout << "Priority: ";
        cin >> newnode->priority;
        cout << "Execution Time (ms): ";
        cin >> newnode->time;

        insert_node(head, newnode);

        Node *temp = head->next;

        while (temp != NULL)
        {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }

    return 0;
}
