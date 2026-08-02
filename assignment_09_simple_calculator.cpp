// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
void divide(double a, double b);
void modulo(double a, double b);
double power(double base, double exp);

int main() {
    int choice = 0;

    std::cout << std::fixed << std::setprecision(2);

    while (choice != 7) {
        showMenu();
        std::cout << "Enter your choice (1-7): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nError: Invalid choice. Please enter a number from 1 to 7.\n\n";
            continue;
        }

        if (choice == 7) {
            std::cout << "\nGoodbye!\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            std::cout << "\nError: Invalid option. Please select a valid menu option (1-7).\n\n";
            continue;
        }

        double num1 = 0.0, num2 = 0.0;
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nError: Invalid number entered. Returning to menu.\n\n";
            continue;
        }

        std::cout << "\nResult: ";

        switch (choice) {
            case 1:
                std::cout << num1 << " + " << num2 << " = " << add(num1, num2) << "\n";
                break;
            case 2:
                std::cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << "\n";
                break;
            case 3:
                std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << "\n";
                break;
            case 4:
                divide(num1, num2);
                break;
            case 5:
                modulo(num1, num2);
                break;
            case 6:
                std::cout << num1 << " ^ " << num2 << " = " << power(num1, num2) << "\n";
                break;
        }

        std::cout << "\n";
    }

    return 0;
}

void showMenu() {
    std::cout << "================================\n";
    std::cout << "     SIMPLE CALCULATOR\n";
    std::cout << "================================\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Modulus\n";
    std::cout << "6. Exponentiation\n";
    std::cout << "7. Quit\n";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

void divide(double a, double b) {
    if (b == 0.0) {
        std::cout << "Error: Cannot divide by zero.\n";
    } else {
        std::cout << a << " / " << b << " = " << (a / b) << "\n";
    }
}

void modulo(double a, double b) {
    if (b == 0.0) {
        std::cout << "Error: Cannot perform modulus by zero.\n";
    } else {
        std::cout << a << " % " << b << " = " << std::fmod(a, b) << "\n";
    }
}

double power(double base, double exp) {
    return std::pow(base, exp);
}