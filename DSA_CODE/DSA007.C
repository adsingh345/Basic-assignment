#include <stdio.h>

// Recursive function to find n-th Fibonacci number
int fib(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive step
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", fib(n));
    }
    return 0;
}
