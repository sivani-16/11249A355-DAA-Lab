#include <stdio.h>

// Recursive function to calculate the n-th Fibonacci number
int fibonacci_recursive(int n) {
    // Base conditions: F(0) = 0, F(1) = 1
    if (n <= 1) {
        return n;
    }
    // Recursive case: F(n) = F(n-1) + F(n-2)
    else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int main() {
    int n = 10; // Number of terms to generate
    printf("Fibonacci Series using Recursion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");
    return 0;
}
