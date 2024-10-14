//Task: Write a C++ program to check the strength of a password based on various criteria. 
//Define functions to check for the presence of uppercase letters, lowercase letters, digits, 
//and special characters. The program should provide feedback on how to improve the password strength.

#include <iostream>
#include <string>
#include <cctype> // for character checking functions

using namespace std;

// Function to check for uppercase letters
bool hasUppercase(const string& password) {
    for (char ch : password) {
        if (isupper(ch)) {
            return true;
        }
    }
    return false;
}

// Function to check for lowercase letters
bool hasLowercase(const string& password) {
    for (char ch : password) {
        if (islower(ch)) {
            return true;
        }
    }
    return false;
}

// Function to check for digits
bool hasDigit(const string& password) {
    for (char ch : password) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

// Function to check for special characters
bool hasSpecialChar(const string& password) {
    string specialChars = "!@#$%^&*()-_=+[{]}|;:'\",<.>/?`~";
    for (char ch : password) {
        if (specialChars.find(ch) != string::npos) {
            return true;
        }
    }
    return false;
}

// Function to check the password strength
void checkPasswordStrength(const string& password) {
    bool upper = hasUppercase(password);
    bool lower = hasLowercase(password);
    bool digit = hasDigit(password);
    bool special = hasSpecialChar(password);
    bool lengthValid = password.length() >= 8;

    // Display feedback
    cout << "\nPassword Strength Check:\n";
    
    if (lengthValid && upper && lower && digit && special) {
        cout << "Strong password!\n";
    } else {
        cout << "Your password could be stronger. Suggestions:\n";
        if (!lengthValid) {
            cout << "- Make sure your password is at least 8 characters long.\n";
        }
        if (!upper) {
            cout << "- Add at least one uppercase letter (A-Z).\n";
        }
        if (!lower) {
            cout << "- Add at least one lowercase letter (a-z).\n";
        }
        if (!digit) {
            cout << "- Add at least one digit (0-9).\n";
        }
        if (!special) {
            cout << "- Add at least one special character (e.g., !, @, #, $, etc.).\n";
        }
    }
}

int main() {
    string password;

    // Prompt user for password input
    cout << "Enter your password: ";
    cin >> password;

    // Check the strength of the password
    checkPasswordStrength(password);

    return 0;
}
