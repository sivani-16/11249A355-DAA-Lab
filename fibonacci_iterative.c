#include <stdio.h>

// Function to generate the Fibonacci series using iteration
void fibonacci_iterative(int n) {
    int num1 = 0, num2 = 1, nextNum;
    printf("Fibonacci Series using Iteration: ");

    for (int i = 0; i < n; ++i) {
        printf("%d ", num1);
        nextNum = num1 + num2; // Calculate the next number
        num1 = num2;         // Update num1 to the previous num2
        num2 = nextNum;      // Update num2 to the new nextNum
    }
    printf("\n");
}

int main() {
    int n = 10; // Number of terms to generate
    fibonacci_iterative(n);
    return 0;
}
