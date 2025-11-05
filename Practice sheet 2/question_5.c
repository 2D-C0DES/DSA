#include <stdio.h>

int main() {
    int arr[100];
    int size;
    float mean, variance, sum = 0.0, sumSquaredDiff = 0.0;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid size. Enter valid size.\n");
        return 1;
    }

    // Read the elements of the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the mean
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    mean = sum / size;

    // Calculate the variance
    for (int i = 0; i < size; i++) {
        sumSquaredDiff += (arr[i] - mean) * (arr[i] - mean);
    }
    variance = sumSquaredDiff / size;

    // Display the variance
    printf("The variance of the array elements is: %.2f\n", variance);

    return 0;
}
