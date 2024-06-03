#include <stdio.h>

#define MAX_SIZE 100

int linearSearch(int arr[], int size, int element) {
	int i;
    for ( i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  // Return the index of the element if found
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[MAX_SIZE], size, element, result;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    int i;
    for ( i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    // Perform the linear search
    result = linearSearch(arr, size, element);

    // Print the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

