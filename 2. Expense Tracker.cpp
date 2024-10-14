//2. Expense Tracker
//Task: Write a C++ program to track personal expenses. Define functions to add expenses, 
//calculate the total expenditure, and categorize expenses by type (e.g., food, transport). 
//The program should allow the user to input and view expense details.



#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for formatting output

using namespace std;

// Structure to represent an expense
struct Expense {
    string type;  // Type of expense (e.g., food, transport)
    string description; // Description of the expense
    double amount; // Amount spent
};

// Function to add a new expense
void addExpense(vector<Expense>& expenses) {
    Expense newExpense;
    cout << "Enter expense type (e.g., food, transport, etc.): ";
    cin >> newExpense.type;
    cout << "Enter a short description: ";
    cin.ignore(); // To consume the newline character left in the input buffer
    getline(cin, newExpense.description);
    cout << "Enter the amount: ";
    cin >> newExpense.amount;

    expenses.push_back(newExpense);
    cout << "Expense added successfully!\n";
}

// Function to calculate total expenditure
double calculateTotal(const vector<Expense>& expenses) {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.amount;
    }
    return total;
}

// Function to display expenses by category
void displayExpensesByType(const vector<Expense>& expenses) {
    string type;
    cout << "Enter the type of expenses to display (e.g., food, transport): ";
    cin >> type;

    cout << "\nExpenses for type: " << type << endl;
    cout << left << setw(15) << "Description" << setw(10) << "Amount" << endl;
    cout << "---------------------------------\n";

    double categoryTotal = 0.0;
    for (const auto& expense : expenses) {
        if (expense.type == type) {
            cout << left << setw(15) << expense.description << setw(10) << expense.amount << endl;
            categoryTotal += expense.amount;
        }
    }

    cout << "Total expenditure for " << type << ": " << categoryTotal << endl;
}

// Function to display all expenses
void displayAllExpenses(const vector<Expense>& expenses) {
    cout << "\nAll Expenses:\n";
    cout << left << setw(15) << "Type" << setw(15) << "Description" << setw(10) << "Amount" << endl;
    cout << "---------------------------------------------\n";
    
    for (const auto& expense : expenses) {
        cout << left << setw(15) << expense.type << setw(15) << expense.description << setw(10) << expense.amount << endl;
    }
    
    cout << "Total expenditure: " << calculateTotal(expenses) << endl;
}

int main() {
    vector<Expense> expenses; // Vector to store the list of expenses
    int choice;

    while (true) {
        // Display menu
        cout << "\nExpense Tracker Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses by Category\n";
        cout << "3. View All Expenses\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle menu choices
        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                displayExpensesByType(expenses);
                break;
            case 3:
                displayAllExpenses(expenses);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
