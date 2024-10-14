//1. Digital Clock Simulation
//Task: Write a C++ program to simulate a digital clock. Define functions to update the time every second and display the current time in HH:MM
//format. Use loops and conditionals to handle time updates and display.

#include <iostream>
#include <iomanip> 
#include <thread> 
#include <chrono>  

using namespace std;

// Function to display the current time in HH:MM format
void displayTime(int hours, int minutes) {
    // Display hours and minutes with leading zeros if needed
    cout << setw(2) << setfill('0') << hours << ":"
         << setw(2) << setfill('0') << minutes << endl;
}

// Function to update the time every second
void updateClock(int &hours, int &minutes) {
    while (true) {
        // Display current time
        displayTime(hours, minutes);

        // Wait for 1 second
        this_thread::sleep_for(chrono::seconds(1));

        // Update minutes
        minutes++;
        
        // Check if minutes overflow
        if (minutes >= 60) {
            minutes = 0;
            hours++;
        }

        // Check if hours overflow
        if (hours >= 24) {
            hours = 0;
        }

        // Clear the previous output (optional)
        system("clear"); // Use "cls" on Windows instead of "clear"
    }
}

int main() {
    // Initialize clock with default time (e.g., 00:00)
    int hours = 0, minutes = 0;

    // Call the function to update the clock
    updateClock(hours, minutes);

    return 0;
}
