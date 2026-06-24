#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string AccNumber;
    string Name;
    double Balance;
    
public:
    BankAccount(string accN, string nm, double initialBalance = 0.0) {
        AccNumber = accN;
        Name = nm;
        Balance = initialBalance;
    }
    
    string get_AccNumber() { return AccNumber; }
    
    string get_Name() { return Name; }
    
    double get_Balance() { return Balance; }
    
    void detail() {
        cout << "Account Number : " << AccNumber << endl;
        cout << "Holder Name : " << Name << endl;
        cout << "Total Balance : " << fixed << setprecision(2) << Balance << endl << endl;
    }
    
    bool deposit(double amount) {
        if(amount <= 0) {
            return false;
        } else {
            Balance += amount;
        }
        return true;
    }
    
    bool withdraw(double amount) {
        if(amount <=0 || amount > Balance) {
            return false;
        } else {
            Balance -= amount;
        }
        return true;
    }
};

class BankSystem {
private:
    vector<BankAccount> accounts;
    int nextAccNumber = 1;
    
    string generateAccNo() {
        return "ACC" + to_string(1000 + nextAccNumber++);
    }
    
    BankAccount* findaccout(string accNo) {
        for(auto &account : accounts) {
            if(account.get_AccNumber() == accNo) {
                return &account;
            }
        }
        return nullptr;
    }
    
public:
    
    void creatAccount() {
        string accN;
        string name;
        double amount;
        
        accN = generateAccNo();
        cout << "The Account Number : " << accN << endl;

        BankAccount* account = findaccout(accN);
        
        if(account != nullptr) {
            cout << "Account alredy Exists\n";
            return;
        }
        
        cout << "Enter holder Name : ";
        getline(cin >> ws, name);
        
        cout << "Enter initial Amount : ";
        cin >> amount;
        
        accounts.emplace_back(accN, name, amount);
        cout << "Creat Account Successfully\n";
    }
    
    void showAccount() {
        string accN;
        
        cout << "Enter account Number : ";
        getline(cin >> ws, accN);
        
        BankAccount* account = findaccout(accN);
        
        if(account == nullptr) {
            cout << "Account Not found\n";
            return;
        } else {
            account->detail();
        }
    }
    
    void depositMoney() {
        string accN;
        double amount;
        
        cout << "Enter Account Number : ";
        getline(cin >> ws, accN);
        
        BankAccount* account = findaccout(accN);
        if(account == nullptr) {
            cout << "Account Not found\n";
            return;
        }
        
        cout << "Enter Deposit amount : ";
        cin >> amount;
        
        if(account->deposit(amount)) {
            cout << "Deposit successfull. New Balance : ";
            cout << fixed << setprecision(2) << account->get_Balance() << endl;
        } else {
            cout << "Enter valide money \n";
        }
    }
    
    void withdrawMoney() {
        string accN;
        double amount;
        
        cout << "Enter account Number : ";
        getline(cin >> ws, accN);
        
        BankAccount* account = findaccout(accN);
        
        if(account == nullptr) {
            cout << "Account Not found\n";
            return;
        } 
        
        cout << "Enter Withdraw amount : ";
        cin >> amount;
        
        if(account->withdraw(amount)) {
            cout << "Withdraw successfull. New Balance : ";
            cout << fixed << setprecision(2) << account->get_Balance();
        } else {
            cout << "The Balance is low as per required\n";
        }
    }
    
    void tranceMoney() {
        string from_acc, to_acc;
        double amount;
        
        cout << "Enter sencer account Number : ";
        getline(cin >> ws, from_acc);
        
        cout << "Enter reciver account Number : ";
        getline(cin >> ws, to_acc);
        
        BankAccount* sender_acc = findaccout(from_acc);
        BankAccount* reciver_acc = findaccout(to_acc);
        
        if(sender_acc == nullptr || reciver_acc == nullptr) {
            cout << "account one or both Not found\n";
            return;
        }
        
        cout << "Enter transfer amount : ";
        cin >> amount;
        
        if(sender_acc->withdraw(amount)) {
            cout << "sender account withdraw successful : "<< fixed << setprecision(2) << sender_acc->get_Balance() << endl;
            
            if(reciver_acc->deposit(amount)) {
                cout << "reciver account deposit successful : "<< fixed << setprecision(2) << reciver_acc->get_Balance() << endl;
            }
        } else {
            cout << "Check Bouns. Better Luck next time \n";
        }
        
    }
    
    void show_Accounts() {
        if(accounts.empty()) {
            cout << "No Account Available\n";
            return;
        }
        
        cout << "\n--- All Accounts ---\n";
        for(auto& account : accounts) {
            account.detail();
        }
    }
};

int main() {
    BankSystem bank;
    
    int choice;
    
    do {
        cout << "\n===== Bank Account Management System =====\n";
        
        cout << "1. Creat The Account \n";
        cout << "2. Show Account \n";
        cout << "3. Deposite Money\n";
        cout << "4. withdraw Money\n";
        cout << "5. Trancefar Money \n";
        cout << "6. Show all accounts detail \n";
        cout << "0. Exite\n";
        cout << "Enter choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                bank.creatAccount(); break;
            case 2:
                bank.showAccount(); break;
            case 3:
                bank.depositMoney(); break; 
            case 4:
                bank.withdrawMoney(); break;
            case 5:
                bank.tranceMoney(); break;
            case 6: 
                bank.show_Accounts();  break;
            case 0:
                cout << "Thank you so Much to visit \n";
                break;
            default:
                cout << "Enter valid Number as above mention\n";
        } 
    } while(choice != 0);
    
    return 0;
}
