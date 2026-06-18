#include <iostream>
#include <vector>
using namespace std;

class Bank {
private:
    string holderName;
    string accountNumber;
    int balance;

public:
    Bank(string name, string accNumber, int initial) {
        holderName = name;
        accountNumber = accNumber;
        balance = initial;
    }
    
    string get_name() {
        return holderName;
    }
    string get_accNumber() {
        return accountNumber;
    }
    int get_balance() {
        return balance;
    }
    
    void detail() {
        cout << "Holder Name : " << get_name() << endl;
        cout << "Holder account Number : " << get_accNumber() << endl;
        cout << "Holder Balance : " << get_balance() << endl; 
    }
    
    void deposite() {
        int amount;
        cout << "Enter deposit amount : ";
        cin >> amount;
        
        if(amount > 0) {
        balance += amount;
        cout << "you deposit is succeful " << amount << "$"<< endl;
        cout << "new dalace " << balance << "$" << endl; 
        }
        else {
            cout << "Invalid amount retry" << endl;
        }
    }
    void withdraw() {
        int amount;
        cout << "Enter withdraw amount : ";
        cin >> amount;
        
        if(amount > 0 && amount < balance) {
        balance -= amount;
        cout << "you deposit is succeful " << amount << "$"<< endl;
        cout << "new balace " << balance << "$" << endl; 
        }
        else {
            cout << "Invalid amount retry" << endl;
        }
    }
};

int main() {
    string nm, accNum;
    int amount;
    
    cout << "Enter Name : ";
    getline(cin >> ws, nm);
    
    cout << "Enter Account Number : ";
    getline(cin >> ws, accNum);
    
    cout << "Enter initial Amount : "; 
    cin >> amount;
    
    Bank b(nm, accNum, amount);
    int choice;
    
    do {
        cout << "1. deposit " << endl;
        cout << "2. withdraw " << endl;
        cout << "3. show detail " << endl;
        cout << "4. Exit " << endl;
        cin >> choice;
        
        switch(choice) {
            case 1:
                b.deposite();
                break;
            
            case 2:
                b.withdraw();
                break;
                
            case 3:
                b.detail();
                break;
            
            case 4:
                cout << "Thank you so much to use this system" << endl;
                break;
            
            default:
                cout << "Invalid try again" << endl;
                break;
        }
    } while(choice != 4);
    
    return 0;
}
