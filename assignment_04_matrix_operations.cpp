// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int MAX_SIZE = 10;

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int M = 0; M < rows; M++) {
        for (int N = 0; N < cols; N++) {
            cout << setw(6) << matrix[M][N];
        }
        cout << endl;
    }
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name = "Matrix") {
    for (int M = 0; M < rows; M++) {
        for (int N = 0; N < cols; N++) {
            cout << "Enter element [" << M << "][" << N << "]: ";
            cin >> matrix[M][N];
        }
    }
}

void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int rows, int cols, int dest[MAX_SIZE][MAX_SIZE]) {
    for (int M = 0; M < rows; M++) {
        for (int N = 0; N < cols; N++) {
            dest[N][M] = src[M][N];
        }
    }
}

void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int M = 0; M < rows; M++) {
        for (int N = 0; N < cols; N++) {
            result[M][N] = A[M][N] + B[M][N];
        }
    }
}

void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], int rowsA, int colsA,
                      const int B[MAX_SIZE][MAX_SIZE], int rowsB, int colsB,
                      int result[MAX_SIZE][MAX_SIZE]) {

    for (int M = 0; M < rowsA; M++) {
        for (int P = 0; P < colsB; P++) {
            result[M][P] = 0;
            for (int N = 0; N < colsA; N++) {
                result[M][P] += A[M][N] * B[N][P];
            }
        }
    }
}

int main() {
    int choice;
    cout << "MATRIX OPERATIONS" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        cout << "\nPART A: Transpose Matrix" << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        
        int mat[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        inputMatrix(mat, rows, cols);

        transposeMatrix(mat, rows, cols, result);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(mat, rows, cols);

        cout << "\nTransposed Matrix (" << cols << " x " << rows << "):" << endl;
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        int rows, cols;
        cout << "\nPART B: Add Two Matrices" << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        
        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "\nInput Matrix A:" << endl;
        inputMatrix(A, rows, cols);

        cout << "\nInput Matrix B:" << endl;
        inputMatrix(B, rows, cols);

        addMatrices(A, B, rows, cols, result);

        cout << "\nResult of Addition:" << endl;
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        int rowsA, colsA, rowsB, colsB;
        cout << "\nPART C: Multiply Two Matrices" << endl;
        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << "Error: Number of columns in A (" << colsA
                 << ") must equal number of rows in B (" << rowsB << ")." << endl;
            return 1;
        }

        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "\nInput Matrix A:" << endl;
        inputMatrix(A, rowsA, colsA);

        cout << "\nInput Matrix B:" << endl;
        inputMatrix(B, rowsB, colsB);

        multiplyMatrices(A, rowsA, colsA, B, rowsB, colsB, result);

        cout << "\nResult of Multiplication (" << rowsA << " x " << colsB << "):" << endl;
        printMatrix(result, rowsA, colsB);

    } else {
        cout << "Invalid choice! Program terminating." << endl;
    }
    return 0;
}