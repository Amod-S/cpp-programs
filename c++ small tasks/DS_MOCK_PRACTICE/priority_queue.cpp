/*11. Simple Task Scheduler (Singly Linked List)
Write a program that implements a simple task scheduler using a singly linked list.
Each node in the linked list represents a task with its priority and execution time.
Tasks are scheduled based on their priority, with higher priority tasks being
executed first.*/

/*Sample output:
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
.
All tasks executed.*/

#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
    int priority;
    int exec_time;
};

Node *createNode(string data, int priority, int exec_time)
{
    Node *newnode = new Node();
    newnode->data = data;
    newnode->exec_time = exec_time;
    newnode->priority = priority;
    newnode->next = nullptr;

    return newnode;
}

void schedule_tasks(Node *&head, Node *newnode)
{
    // if no nodes are there
    if (head == nullptr)
    {
        head = newnode;
        return;
    } // endif

    // if priority of newnode is more than 1st node(pointed at by head)
    if (newnode->priority > head->priority)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node *temp = head;
    Node *temp2 = temp;

    // if priority of newnode is midway or at last in the queue
    while (temp->priority > newnode->priority && temp->next != nullptr)
    {
        temp2 = temp;
        temp = temp->next;
    }

    if (temp->priority > newnode->priority)
    {
        temp->next = newnode;
        return;
    }
    newnode->next = temp;
    temp2->next = newnode;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "No tasks scheduled." << endl;
        return;
    }

    cout << "\nScheduled Tasks (Highest Priority First):\n";

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << "Task: " << temp->data
             << ", Priority: " << temp->priority
             << ", Execution Time: " << temp->exec_time
             << " ms" << endl;

        temp = temp->next;
    }

    cout << "\nExecuting Tasks:\n";

    temp = head;

    while (temp != nullptr)
    {
        cout << "Executing Task '" << temp->data
             << "' [Priority: " << temp->priority
             << "] for " << temp->exec_time
             << " ms..." << endl;

        temp = temp->next;
    }

    cout << "\nAll tasks executed." << endl;
}

int main()
{
    int no_tasks;
    string task_name;
    int priority;
    int exec_time;

    cout << "Enter number of tasks." << endl;
    cin >> no_tasks;

    Node *head = nullptr;

    for (int i = 0; i < no_tasks; i++)
    {
        cout << "Task " << i + 1 << " name: ";
        cin >> task_name;
        cout << "Priority (higher = more important): ";
        cin >> priority;
        cout << "Execution Time (ms): ";
        cin >> exec_time;

        Node *newnode = createNode(task_name, priority, exec_time);

        schedule_tasks(head, newnode);
    }
    display(head);

    return 0;
}