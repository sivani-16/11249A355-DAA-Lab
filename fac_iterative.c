#include <stdio.h>
unsigned long long factorial(int n) {
    unsigned long long fact = 1;

    // Loop from 1 to n, multiplying the current result by the loop index
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    
    return fact;
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Error: Please enter a valid non-negative integer.\n");
        return 1;
    }

    printf("Factorial of %d is %llu\n", num, factorial(num));
    return 0;
}
