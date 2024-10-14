//Task: Write a C++ program to simulate a basic banking system. Define functions for creating accounts, 
//depositing money, withdrawing money, and checking balances. Use a data structure to manage multiple accounts and transactions.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a bank account
struct Account {
    int accountNumber;
    string accountHolder;
    double balance;
};

// Function to create a new account
void createAccount(vector<Account>& accounts) {
    Account newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter account holder name: ";
    cin.ignore(); // Clear newline from input buffer
    getline(cin, newAccount.accountHolder);
    newAccount.balance = 0.0;

    accounts.push_back(newAccount);
    cout << "Account created successfully!\n";
}

// Function to find an account by account number
Account* findAccount(vector<Account>& accounts, int accountNumber) {
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            return &account;
        }
    }
    return nullptr; // If not found, return null
}

// Function to deposit money into an account
void depositMoney(vector<Account>& accounts) {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    Account* account = findAccount(accounts, accountNumber);
    if (account != nullptr) {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            account->balance += amount;
            cout << "Deposited " << amount << " successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    } else {
        cout << "Account not found.\n";
    }
}

// Function to withdraw money from an account
void withdrawMoney(vector<Account>& accounts) {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    Account* account = findAccount(accounts, accountNumber);
    if (account != nullptr) {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && account->balance >= amount) {
            account->balance -= amount;
            cout << "Withdrew " << amount << " successfully.\n";
        } else if (amount > 0 && account->balance < amount) {
            cout << "Insufficient balance.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    } else {
        cout << "Account not found.\n";
    }
}

// Function to check account balance
void checkBalance(const vector<Account>& accounts) {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    const Account* account = findAccount(const_cast<vector<Account>&>(accounts), accountNumber);
    if (account != nullptr) {
        cout << "Account holder: " << account->accountHolder << endl;
        cout << "Current balance: " << account->balance << endl;
    } else {
        cout << "Account not found.\n";
    }
}

// Main function to simulate the banking system
int main() {
    vector<Account> accounts;
    int choice;

    while (true) {
        // Display menu
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
