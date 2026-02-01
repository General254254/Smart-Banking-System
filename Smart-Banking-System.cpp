#include <iostream>
using namespace std;

class Account {
    private:
        int accountNumber;
        string accountOwner;
        double balance;
    public:
        Account(int accNum, string owner) {
            accountNumber = accNum;
            accountOwner = owner;
            balance = 0.0;
        }

        void deposit(double amount) {
            if (amount <= 0) {
                cout<<"invalid deposit amount!"<<endl;
            } else if (amount > 10000) {
                cout<<"Deposit amount exceeds limit!"<<endl;
            } else {
                balance += amount;
                cout<<"Deposited: "<<amount<<endl;
            }
        }

        virtual void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout<<"Withdrawn: "<<amount<<endl;
            } else {
                cout<<"Invalid withdrawal amount!"<<endl;
            }
        }

        virtual void displayAccountInfo() {
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Account Owner: "<<accountOwner<<endl;
            cout<<"Balance: "<<balance<<endl;
        }

        double getBalance() {
            return balance;
        }

    };

class SavingsAccount : public Account {
    private:
        double interestRate;
    public:
        SavingsAccount(int accNum, string owner, double rate) : Account(accNum, owner) {
            interestRate = rate;
        }
        void withdraw(double amount) override {
            if (500 > amount && amount <= getBalance()) {
                Account::withdraw(amount);
            } else {
                cout<<"Insufficient funds for withdrawal in Savings Account!"<<endl;
            }
        }

        void addInterest() {
            double interest = getBalance() * (interestRate / 100);
            deposit(interest);
            cout<<"Interest added: "<<interest<<endl;
        }
    };

    class CurrentAccount : public Account {
    private:
        double overdraftLimit;
    public:
        CurrentAccount(int accNum, string owner, double limit) : Account(accNum, owner) {
            overdraftLimit = limit;
        }

        void withdraw(double amount) override {
            if (amount > 0 && amount <= getBalance() + overdraftLimit) {
                Account::withdraw(amount);
            } else {
                cout<<"Withdrawal exceeds overdraft limit in Current Account!"<<endl;
            }
        }

        void displayAccountInfo() override {
            Account::displayAccountInfo();
            cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
        }
    };
int main() {git 

    Account* acc;   // base class pointer

    SavingsAccount savingsAcc(1001, "Alice", 5.0);
    CurrentAccount currentAcc(2001, "Bob", 500);

    // Point to SavingsAccount
    acc = &savingsAcc;
    acc->deposit(1000);
    acc->withdraw(200);        // calls SavingsAccount::withdraw()
    acc->displayAccountInfo(); // calls Account version (not overridden)

    cout << "------------------" << endl;

    // Point to CurrentAccount
    acc = &currentAcc;
    acc->deposit(300);
    acc->withdraw(700);        // calls CurrentAccount::withdraw()
    acc->displayAccountInfo(); // calls CurrentAccount::displayAccountInfo()

    return 0;
}