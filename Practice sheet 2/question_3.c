#include <stdio.h>

int main() {
    int arr[100];
    int size;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid size. Please enter a value between 1 and 100.\n");
        return 1;
    }

    // Read the elements of the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize min and max
    int min = arr[0];
    int max = arr[0];

    // Find min and max
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Display the results
    printf("The minimum element is: %d\n", min);
    printf("The maximum element is: %d\n", max);

    return 0;
}
