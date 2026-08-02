// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in


#include <iostream>
using namespace std;


void printSingleTable(int num);
void printMultipleTables(int n);

int main() {
    int choice = 0;
    int num = 0;

    std::cout << "Select an Option:\n";
    std::cout << "1. Print a single multiplication table\n";
    std::cout << "2. Print multiplication tables (1 to n)\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (std::cin.fail() || (choice != 1 && choice != 2)) {
        std::cout << "Error: Invalid selection. Please choose option 1 or 2." << std::endl;
        return 1;
    }

    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (std::cin.fail() || num <= 0) {
      std::cout << "Error: Invalid input. Please enter a positive integer." << std::endl;
      return 1; 
  }

    std::cout << "\n";

    if (choice == 1) {
        printSingleTable(num);
    } else if (choice == 2) {
        printMultipleTables(num);
   }

   return 0;
}

void printSingleTable(int num) {
    std::cout << "Multiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; ++i) {
        std::cout << num << " x " << i << " = " << (num * i) << "\n";
    }
}

void printMultipleTables(int n) {
    for (int i = 1; i <= n; ++i) {
        std::cout << "Multiplication Table for " << i << ":\n";

        for (int j = 1; j <= 12; ++j) {
            std::cout << i << " x " << j << " = " << (i * j) << "\n";
        }

        std::cout << "---------------------------\n";
    }
}