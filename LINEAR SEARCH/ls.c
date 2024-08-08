#include <stdio.h>

int LinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++ ) {
        if (arr[i] == target) {
            return i;  // Return the index of the found element
        }
    }
    return -1;  // Element not found
}

int main() {
    int size, target;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];  // Declare the array with the specified size

    // Input the elements of the array
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target value to search for
    printf("Enter the target element: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    // Output the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
