/*Topics: Classes, Objects, Data Members, Methods

Assignment 1: Student
Data:
- Name
- Roll Number
- Marks

Functions:
- Input
- Display
- Calculate percentage


Goal:

Create objects
Call methods
Understand class organization
*/
#include <iostream>
using namespace std;

class Student
{
    string name;
    int roll_no;
    float marks;

public:
    // setter
    void get_data(string n, int rollNo, float grade)
    {
        name = n;
        roll_no = rollNo;
        marks = grade;
    }
    void display_data()
    {
        cout << "Student Data:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll number: " << roll_no << endl;
        cout << "Marks: " << marks << endl;
    }
    float calc_percentage(int total)
    {
        float percentage = (marks / total) * 100;
        return percentage;
    }
};

int main()
{
    string name;
    int roll_no;
    float marks;
    int total;
    Student s1;
    cout << "Enter student details." << endl;
    cin >> name >> roll_no >> marks;
    s1.get_data(name, roll_no, marks);
    s1.display_data();
    cout << "Enter total marks" << endl;
    cin >> total;
    cout << s1.calc_percentage(total) << endl;
}