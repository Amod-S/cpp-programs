/*Employee Information System
Develop a program in C++ to create a database of an employee's information system
containing the following fields: Name, employee ID, Department, Date of Joining,
Contact address, Telephone number etc. Construct the database with suitable member
functions to accept and print employee details. Make use of constructor types,
destructor, static members, inline function and dynamic memory allocation using
operators-new and delete.*/
#include <iostream>
#include <string>
using namespace std;

class Employee
{
    string name;
    int emp_id;
    string department, dateOfJoining;
    string address;
    int tele_number;

    static string company_name;

public:
    // Default constructor
    Employee()
    {
        name = department = dateOfJoining = address = "";
        emp_id = 0;
        tele_number = 0;
    }

    // Parameterized constructor
    Employee(string name, int id, string dept,
             string doj, string addr, int telNum)
    {
        this->name = name;
        emp_id = id;
        department = dept;
        dateOfJoining = doj;
        address = addr;
        tele_number = telNum;
    }

    // Copy constructor
    Employee(const Employee &obj)
    {
        name = obj.name;
        emp_id = obj.emp_id;
        department = obj.department;
        dateOfJoining = obj.dateOfJoining;
        address = obj.address;
        tele_number = obj.tele_number;
    }

    // Destructor
    ~Employee()
    {
        cout << "Object destroyed" << endl;
    }

    void setEmpData(string name, int id, string dept,
                    string doj, string addr, int telNum);

    void displayDetails();

    // Static member function
    static void displayCompanyName()
    {
        cout << "Company Name: " << company_name << endl;
    }

    // Inline member function
    inline void showCompany()
    {
        displayCompanyName();
    }
};

// Definition of static member
string Employee::company_name = "XYZ Pvt Ltd";

void Employee::setEmpData(string name, int id, string dept,
                          string doj, string addr, int telNum)
{
    this->name = name;
    emp_id = id;
    department = dept;
    dateOfJoining = doj;
    address = addr;
    tele_number = telNum;
}

void Employee::displayDetails()
{
    cout << "\n----- Employee Details -----\n";
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << emp_id << endl;
    cout << "Department: " << department << endl;
    cout << "Date of Joining: " << dateOfJoining << endl;
    cout << "Contact Address: " << address << endl;
    cout << "Telephone Number: " << tele_number << endl;
}

int main()
{
    // 1. Default Constructor
    Employee emp1;
    emp1.setEmpData("Amod", 101, "IT",
                    "01-01-2025",
                    "Pune", 123456);

    // 2. Parameterized Constructor
    Employee emp2("Rahul", 102, "HR",
                  "15-02-2024",
                  "Mumbai", 654321);

    // 3. Copy Constructor
    Employee emp3(emp2);

    cout << "\nDefault Constructor Object:";
    emp1.displayDetails();

    cout << "\nParameterized Constructor Object:";
    emp2.displayDetails();

    cout << "\nCopy Constructor Object:";
    emp3.displayDetails();

    // 4. Dynamic Memory Allocation
    Employee *emp4 = new Employee(
        "Priya", 103, "Finance",
        "10-03-2023",
        "Delhi", 987654);

    cout << "\nDynamic Object using new:";
    emp4->displayDetails();

    delete emp4; // Destructor called

    cout << "\nDisplaying Company Name using Static Function:\n";
    Employee::displayCompanyName();

    cout << "\nDisplaying Company Name using Inline Function:\n";
    emp1.showCompany();

    return 0;
}