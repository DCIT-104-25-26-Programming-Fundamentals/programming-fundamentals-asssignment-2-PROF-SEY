// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>
using namespace std;


struct Student {
    std::string name;
    int id;
    std::vector<double> scores;
};

void showMenu();
void addStudent(std::vector<Student>& students);
void displayAllStudents(const std::vector<Student>& students);
void calculateAverageScore(const std::vector<Student>& students);

int main() {
    std::vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        showMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nError: Invalid option. Please enter a number from 1 to 4.\n\n";
            continue;
        }

        std::cout << "\n";

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageScore(students);
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Error: Invalid selection. Please choose an option from 1 to 4.\n";
                break;
        }

        std::cout << "\n";
    }

    return 0;
}

void showMenu() {
    std::cout << "================================\n";
    std::cout << "   STUDENT RECORD SYSTEM MENU\n";
    std::cout << "================================\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Display All Students\n";
    std::cout << "3. Calculate Average Score\n";
    std::cout << "4. Quit\n";
}

void addStudent(std::vector<Student>& students) {
    Student newStudent;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Student name: ";
    std::getline(std::cin, newStudent.name);

    std::cout << "Student ID: ";
    std::cin >> newStudent.id;

    if (std::cin.fail() || newStudent.id <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid ID. Student addition canceled.\n";
        return;
    }

    int numScores = 0;
    std::cout << "How many scores? ";
    std::cin >> numScores;

    if (std::cin.fail() || numScores < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid number of scores. Student addition canceled.\n";
        return;
    }

    for (int i = 0; i < numScores; ++i) {
        double score = 0.0;
        std::cout << "Enter score " << (i + 1) << ": ";
        std::cin >> score;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Warning: Invalid score entered. This score will be skipped.\n";
            continue;
        }
        newStudent.scores.push_back(score);
    }
    
    students.push_back(newStudent);
    std::cout << "Student added successfully!\n";
}

void displayAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records found.\n";
        return;
    }

    std::cout << "All Student Records:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "ID: " << students[i].id << ", Name: " << students[i].name << "\n";
        std::cout << "  Scores: ";
        if (students[i].scores.empty()) {
            std::cout << "No scores recorded";
        } else {
            for (size_t j = 0; j < students[i].scores.size(); ++j) {
                std::cout << students[i].scores[j] << (j + 1 < students[i].scores.size() ? ", " : "");
            }
        }
        std::cout << "\n\n";
    }
}

void calculateAverageScore(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records available.\n";
        return;
    }

    int searchId = 0;
    std::cout << "Enter student ID to calculate average: ";
    std::cin >> searchId;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid ID input.\n";
        return;
    }
    
    for (const auto& student : students) {
        if (student.id == searchId) {
            if (student.scores.empty()) {
                std::cout << student.name << " (ID: " << student.id << ") has no scores recorded.\n";
                return;
            }

            double sum = std::accumulate(student.scores.begin(), student.scores.end(), 0.0);
            double average = sum / student.scores.size();

            std::cout << "Student: " << student.name << " (ID: " << student.id << ")\n";
            std::cout << "Average Score: " << std::fixed << std::setprecision(2) << average << "\n";
            return;
        }
    }

    std::cout << "Error: Student with ID " << searchId << " not found.\n";
}
