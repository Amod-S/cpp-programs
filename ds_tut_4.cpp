#include <iostream>
using namespace std;

struct Node
{
    int data, priority;
    Node *next;
};

int main()
{
    Node *head = NULL; // head points to first node, initially empty
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Node *newnode = new Node();
        newnode->next = NULL;
        cout << "Enter data: ";
        cin >> newnode->data;
        cout << "Enter priority: ";
        cin >> newnode->priority;

        // empty list
        if (head == NULL)
        {
            head = newnode;
        }
        // insert at front
        else if (newnode->priority > head->priority)
        {
            newnode->next = head;
            head = newnode;
        }
        // insert in middle or end
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority >= newnode->priority)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    // Print the list
    Node *temp3 = head;
    int taskNo = 1;
    while (temp3 != NULL)
    {
        cout << "Task " << taskNo++ << ": " << temp3->data << '\n';
        temp3 = temp3->next;
    }

    return 0;
}
