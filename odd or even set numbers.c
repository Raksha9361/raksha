#include <stdio.h>
int main() {
    int n, i, num;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int numbers[n];
    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    } 
    for (i = 0; i < n; i++) {
        num = numbers[i];
        if (num % 2 == 0) {
            printf("%d is even\n", num);
        } else {
            printf("%d is odd\n", num);
        }
    }

    return 0;
}

