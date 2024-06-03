#include <stdio.h>
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
int main() {
    int n;
    unsigned long long result;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        result = factorial(n);
        printf("Factorial of %d = %llu\n", n, result);
    }

    return 0;
}

