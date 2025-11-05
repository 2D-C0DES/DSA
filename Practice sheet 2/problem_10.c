#include <stdio.h>

int hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1;  // Duplicate found
            }
        }
    }
    return 0;  // No duplicates found
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check for duplicates
    if (hasDuplicates(arr, n)) {
        printf("The array contains duplicate values.\n");
    } else {
        printf("The array does not contain any duplicate values.\n");
    }

    return 0;
}
