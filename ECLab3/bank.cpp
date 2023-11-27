#include <iostream>
using namespace std;

class Account {
    protected:
        void construct(string accNum, string holder, double bal) {
            this->accountNumber = accNum;
            this->accountHolder = holder;
            this->balance = bal;
        }
        string accountNumber;
        string accountHolder;
        double balance;
    public:
        void displayDetails(string type) {
            cout.precision(2);
            cout << fixed << "Account Details for " << type << " Account (ID: " << this->accountNumber << "):" << endl;
            cout << " Holder: " << this->accountHolder << endl;
            if (this->balance < 0) {
                cout << " Balance: -$" << -this->balance << endl;
            } else {
                cout << " Balance: $" << this->balance << endl;
            }
        }
        void deposit(double amount) {
            this->balance += max(amount, (double) 0);
        }
        double withdraw(double amount, double belowZero) {
            double prev = this->balance;
            this->balance = max(this->balance - max(amount, (double) 0), -belowZero);
            if (this->balance == 0) this->balance = 0;
            return prev - this->balance;
        }
};

class SavingsAccount: public Account {
    protected:
        double interestRate;
    public:
        SavingsAccount(string accNum, string holder, double bal, double rate) {
            construct(accNum, holder, bal);
            this->interestRate = rate;
        }
        void displayDetails() {
            Account::displayDetails("Savings");
            cout << " Interest Rate: " << this->interestRate*100 << "%\n" << endl;
        }
        double withdraw(double amount) {
            return Account::withdraw(amount, 0);
        }
};

class CurrentAccount: public Account {
    protected:
        double overdraftLimit;
    public:
        CurrentAccount(string accNum, string holder, double bal, double limit) {
            construct(accNum, holder, bal);
            this->overdraftLimit = limit;
        }
        void displayDetails() {
            Account::displayDetails("Current");
            cout << " Overdraft Limit: $" << this->overdraftLimit << endl << endl;
        }
        double withdraw(double amount) {
            return Account::withdraw(amount, this->overdraftLimit);
        }
};

ostream& operator<<(ostream& o, SavingsAccount acc) {
            acc.displayDetails();
            return o;
}
SavingsAccount operator+(SavingsAccount sav, CurrentAccount& cur) {
    sav.deposit(cur.withdraw(300));
    return sav;
}

ostream& operator<<(ostream& o, CurrentAccount acc) {
            acc.displayDetails();
            return o;
}
CurrentAccount operator+(CurrentAccount cur, SavingsAccount& sav) {
    cur.deposit(sav.withdraw(300));
    return cur;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.withdraw(3000);
    current.withdraw(3000);
    
    cout << savings << current;
    
    savings.deposit(300);
    current.deposit(50);
    
    savings.displayDetails();
    current.displayDetails();
    
    current = current + savings;
    
    cout << savings << current;
    
    savings = savings + current;
    
    savings.displayDetails();
    current.displayDetails();
    
    return 0;
}