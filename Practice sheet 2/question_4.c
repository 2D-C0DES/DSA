#include <stdio.h>

int main() {
    int arr[100];
    int size;
    int sum = 0;
    float mean;

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

    // Calculate the sum of elements
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Calculate the mean
    mean = (float)sum / size;

    // Display the mean
    printf("The mean of the array elements is: %.2f\n", mean);

    return 0;
}
