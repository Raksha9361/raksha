#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int array[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        // Move elements of array[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {12, 11, 13, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");
    printArray(array, size);

    insertionSort(array, size);

    printf("Sorted array: \n");
    printArray(array, size);

    return 0;
}
