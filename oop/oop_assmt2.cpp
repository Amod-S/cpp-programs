/*After Videos 4-5

Topics: Constructors

Assignment 2: Bank Account
Data:
- Name
- Account Number
- Balance

Functions:
- Deposit
- Withdraw
- Display


Requirements:

Use parameterized constructor
Prevent negative withdrawals
After Videos 6-7
*/
#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    int acc_num;
    float balance;

public:
    // default constructor
    BankAccount()
    {
        name = "user";
        acc_num = 0;
        balance = 0;
    }
    // parameterized constructor
    BankAccount(string name, int acc_num, float bal)
    {
        // this-> used to avoid naming conflicts.
        this->name = name;
        this->acc_num = acc_num;
        this->balance = bal;
    }
    void deposit(float amt)
    {
        balance += amt;
    }
    void withdraw(float amt)
    {
        if (balance - amt < 0)
        {
            cout << "Not enough balance." << endl;
            return;
        }
        balance -= amt;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Acc number: " << acc_num << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    // call the default values
    BankAccount b1;
    b1.display();
    // use parameterized constructor to set the values
    BankAccount b2("abc", 123, 500.46);
    b2.display();
    // default, then add money to balance
    BankAccount b3;
    b3.deposit(3000.790);
    b3.display();
    // withdraw balance
    b3.withdraw(3000);
    b3.display();
    // withdraw with insufficient balance
    b3.withdraw(300.44);

    return 0;
}