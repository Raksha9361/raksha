#include <stdio.h>

#define MAX_SIZE 100

int binarySearch(int arr[], int size, int element) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element) {
            return mid; // Element found, return its index
        } else if (arr[mid] < element) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[MAX_SIZE], size, element, result;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Input the elements of the array (must be sorted)
    printf("Enter the elements of the array in sorted order:\n");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    // Perform the binary search
    result = binarySearch(arr, size, element);

    // Print the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

