#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Return -1 if the target element is not found
}

int main() {
    int n, target;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Perform the linear search
    int result = linearSearch(arr, n, target);

    // Output the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
   
    }

    return 0 ;
}