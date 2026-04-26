#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 4 // Define the board size, can be changed (e.g., 4, 8)

int board[N + 1]; // Array to store column positions for each row
int count = 0;    // To count the number of solutions

/* Function to check if a queen can be safely placed in a given row and column */
int place(int row, int column) {
    int i;
    for (i = 1; i <= row - 1; ++i) {
        // Check for column conflicts (same column)
        if (board[i] == column) {
            return 0;
        }
        // Check for diagonal conflicts (|board[i] - column| == |i - row|)
        else if (abs(board[i] - column) == abs(i - row)) {
            return 0;
        }
    }
    return 1; // No conflicts found
}

/* Function to print the board configuration for a solution */
void print_board(int n) {
    int i, j;
    printf("\n\nSolution #%d:\n\n", ++count);
    // Print column numbers
    for (i = 1; i <= n; ++i) {
        printf("\t%d", i);
    }
    printf("\n");

    // Print the board
    for (i = 1; i <= n; ++i) {
        printf("%d", i); // Print row number
        for (j = 1; j <= n; ++j) {
            if (board[i] == j) {
                printf("\tQ"); // Queen at this position
            } else {
                printf("\t-"); // Empty spot
            }
        }
        printf("\n");
    }
}

/* Function to solve the N-Queens problem using backtracking */
void queen(int row, int n) {
    int column;
    for (column = 1; column <= n; ++column) {
        if (place(row, column)) {
            board[row] = column; // Place the queen
            if (row == n) {
                print_board(n); // A solution is found, print the board
            } else {
                queen(row + 1, n); // Recurse to place the queen in the next row
            }
            // If the recursive call returns, it means the current placement
            // didn't lead to a solution, so we backtrack and try the next column.
            // No explicit 'unmarking' is needed as the next iteration of the loop
            // or the backtrack to the previous row's function call handles it.
        }
    }
}

int main() {
    // For n=8, there are 92 solutions.
    // For n=4, there are 2 solutions.
    printf("-N queens problem using backtracking-");
    printf("\nEnter number of queens (N): %d", N);
    queen(1, N); // Start with the first row (row 1)
    return 0;
}
