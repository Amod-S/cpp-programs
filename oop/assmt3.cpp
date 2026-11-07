/*Educational Institution System
Design an educational Institution that maintains a database of all
staff members where the database is segregated into a number of classes
having hierarchical relationships.Define all classes with suitable data
members and required member functions to build the database and fetch
individual details.*/
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}
    void display()
    {
        cout << "Name: " << name << "\nID: " << id << endl;
    }
};

class Staff : public Person
{
protected:
    float salary;

public:
    Staff(string n, int i, float s) : Person(n, i), salary(s) {}
    void display()
    {
        Person::display();
        cout << "Salary: " << salary << endl;
    }
};

class TeachingStaff : public Staff
{
    string subject;

public:
    TeachingStaff(string n, int i, float s, string sub)
        : Staff(n, i, s), subject(sub) {}
    void display()
    {
        Staff::display();
        cout << "Subject: " << subject << endl;
    }
};

class NonTeachingStaff : public Staff
{
    string department;

public:
    NonTeachingStaff(string n, int i, float s, string dept)
        : Staff(n, i, s), department(dept) {}
    void display()
    {
        Staff::display();
        cout << "Department: " << department << endl;
    }
};

int main()
{
    TeachingStaff t("Asha", 101, 50000, "Maths");
    NonTeachingStaff n("Ravi", 202, 25000, "Accounts");
    t.display();
    cout << endl;
    n.display();
}