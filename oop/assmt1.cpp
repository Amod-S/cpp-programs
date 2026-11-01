/*Task 1-
Operations on Bank Account
Implement a class to illustrate working of a bank account of a customer that consists
of following members Data members:
i. Name of the customer
ii. Account Type
iii. Account Number
iv. Available balance amount in the account
Member Functions:
i. Assign initial values using constructors.
ii. Deposit an amount in account
iii. Withdraw an amount
iv. Display account details*/

#include <iostream>
using namespace std;

class Bank
{
    string m_name, m_acc_type;
    int m_acc_number;
    float balance;

public:
    // default constructor
    Bank()
    {
        m_name = "user";
        m_acc_type = "savings";
        m_acc_number = -1;
        balance = 0;
    }
    // parameterized constructor
    Bank(string name, string type, int number, float balance)
    {
        this->m_name = name;
        this->m_acc_type = type;
        this->m_acc_number = number;
        this->balance = balance;
    }
    // copy constructor
    Bank(const Bank &obj)
    {
        m_name = obj.m_name;
        m_acc_type = obj.m_acc_type;
        m_acc_number = obj.m_acc_number;
        balance = obj.balance;
    }
    // member functions-
    // deposit
    void deposit(float amt)
    {
        if (amt < 0)
        {
            cout << "You cannot deposit a negative amount of money." << endl;
            return;
        }
        balance += amt;
    }
    // withdraw
    float withdraw(float amt)
    {
        if (amt < 0)
        {
            cout << "You cannot withdraw a negative amount of money." << endl;
            return -1;
        }
        if (balance < amt)
        {
            cout << "There isn't enough balance in your account to withdraw " << amt << " Rs." << endl;
            return -1;
        }
        balance -= amt;
        cout << "Here are your " << amt << " rupees" << endl;
        return amt;
    }
    // display
    void display()
    {
        cout << "Name: " << m_name << endl;
        cout << "Account type: " << m_acc_type << endl;
        cout << "Account number: " << m_acc_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    Bank b1; // default constr called
    b1.deposit(300.45);
    b1.withdraw(20.89);
    b1.withdraw(-2);
    b1.withdraw(500.43);
    b1.display();

    Bank b2("abc", "savings", 12345, 23.34); // param constr
    b2.display();

    Bank b3 = b2; // copy constr
    b3.display();
}