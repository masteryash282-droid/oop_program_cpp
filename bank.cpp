#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
          
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(string accNo, string name, double initialBalance = 0.0)
        : accountNumber(accNo), holderName(move(name)), balance(initialBalance) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getHolderName() const {
        return holderName;
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Account No : " << accountNumber << '\n';
        cout << "Holder Name: " << holderName << '\n';
        cout << "Balance    : " << fixed << setprecision(2) << balance << '\n';
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        balance += amount;
        return true;    
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }
};

class BankSystem {
private:
    vector<BankAccount> accounts;
    
    BankAccount* findaccout(string accNumber) {
        for(auto& account : accounts) {
            if(account.getAccountNumber() == accNumber) {
                return &account;
            }
        }
    return nullptr;
    }

public:
    void createAccount() {
        string accN;
        string name;
        double initialBalance;
        
        cout << "Enter account Number (as you wish) : ";
        getline(cin >> ws, accN);
        
        if(findaccout(accN) != nullptr) {
            cout << "The account is alredy \n";
            return;
        }
        
        cout << "Enter Holder Name : ";
        getline(cin >> ws, name);
        
        cout << "Enter Initial Amount : ";
        cin >> initialBalance;
        
        if(initialBalance <= 0) {
            cout << "Initial Balance can not be negative\n";
        }
        
        accounts.emplace_back(accN, name, initialBalance);
        
        cout << "The account is created successfully\n";
    }
    
    void showAccount() {
        string accN;

        cout << "Enter account Number : ";
        getline(cin >> ws, accN);
        
        BankAccount* account = findaccout(accN);
        
        if(account == nullptr) {
            cout << "The Account Not Fount\n";
            return;
        }
        
        account->display();
    }
    
    void depositMoney() {
        string accN;
        double amount;
        
        cout << "Enter Account Number : ";
        getline(cin >> ws, accN);
        
        BankAccount* account = findaccout(accN);
        if(account == nullptr) {
            cout << "Account Not Fount\n";
        }
        
        cout << "Enter Deposit Money : ";
        cin >> amount;
        
        if(account->deposit(amount)) {
            cout << "Deposit successful. New Balance : " << fixed << setprecision(2) << account->getBalance();
            cout << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
        
    }
    
    void withdrawMoney() {
        string accN;
        double amount;
        
        cout << "Enter Account Number : ";
        getline(cin >> ws, accN);
        
        BankAccount* account = findaccout(accN);
        
        if(account == nullptr) {
            cout << "Account Not found\n";
            return;
        }
        
        cout << "Enter Withdraw Money : ";
        cin >> amount;
        
        if(account->withdraw(amount)) {
            cout << "Withdraw successful. New Balance : " << fixed << setprecision(2) << account->getBalance();
            cout << endl;
        } else {
            cout << "Invalid amount or insufficient balance.\n";
        }
    } 
    
    void transferMoney() {
        string senAcc;
        string recAcc;
        double amount;
        
        cout << "Enter sendr Account Number : ";
        getline(cin >> ws, senAcc);
        
        cout << "Enter reciver Account Number : ";
        getline(cin >>ws, recAcc);
        
        BankAccount* account_1 = findaccout(senAcc);
        BankAccount* account_2 = findaccout(recAcc);
        
        if(account_1 == nullptr || account_2 == nullptr) {
            cout << "One or both Account Not found\n";
        }
        
        if(account_1 == account_2) {
            cout << "Sender and receiver cannot be the same account.\n";
            return;
        }
        
        cout << "Enter amount : ";
        cin >> amount;
        
        if(account_1->withdraw(amount)) { 
            
            if(account_2->deposit(amount)) { 
            cout << "Transfer Money successful.\n";
            }
            
        } else { 
            cout << "Transfer failed. Check amount and balance.\n"; 
            
          }
    }
    
    void listAccounts() {
        if(accounts.empty()) {
            cout << "Not Account is Available \n";
            return;
        }
        
        cout << "\n--- All Accounts ---\n";
        for(const auto& account : accounts) {
            cout << "Accout No: "  << account.getHolderName();
            cout << ", Name : " << account.getHolderName(); 
            cout << ", Balance : " << fixed << setprecision(2) << account.getBalance();
            cout << endl;
        }
    }
};

int main() {
    BankSystem bank;
    int choice;

    do {
        cout << "\n===== Bank Account Management System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Show Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Transfer Money\n";
        cout << "6. List All Accounts\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.showAccount();
                break;
            case 3:
                bank.depositMoney();
                break;
            case 4:
                bank.withdrawMoney();
                break;
            case 5:
                bank.transferMoney();
                break;
            case 6:
                bank.listAccounts();
                break;
            case 7:
                cout << "Thank you for using the system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
