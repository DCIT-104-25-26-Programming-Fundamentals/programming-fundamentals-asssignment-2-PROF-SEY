// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in


#include <iostream>
using namespace std;


void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    int a = 0, b = 1;
    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << a << " ";
        } else if (i == 1) {
            cout << b << " ";
        } else {
            int next = a + b;
            a = b;
            b = next;
            cout << next << " ";
        }
    }
    cout << endl;
}

bool checkFibonacci(int num) {
    if (num < 0) return false;

    int a = 0, b = 1;
    if (num == a || num == b) return true;

    while (b < num) {
        int next = a + b;
        a = b;
        b = next;
    }

    return b == num;
}

int main() {
    int choice;
    cout << "1. Print first N terms\n";
    cout << "2. Check if a number belongs to the sequence\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "How many terms? ";
        cin >> n;
        printFibonacci(n);
    } else if (choice == 2) {
        int num;
        cout << "Enter a number to check: ";
        cin >> num;
        if (checkFibonacci(num)) {
            cout << num << " is a Fibonacci number." << endl;
        } else {
            cout << num << " is NOT a Fibonacci number." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}