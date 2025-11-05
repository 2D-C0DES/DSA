#include <stdio.h>

int main() {
    int arr[100];
    int size;

    printf("Enter the size of the array (max 100): ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid array size. Please enter a value between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    if (size % 2 == 1) {
        // Odd size array
        int middleIndex = size / 2;
        printf("The middle element is: %d\n", arr[middleIndex]);
    } else {
        // Even size array
        int midIndex1 = (size / 2) - 1;
        int midIndex2 = size / 2;
        printf("The middle elements are: %d and %d\n", arr[midIndex1], arr[midIndex2]);
    }

    return 0;
}
