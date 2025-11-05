#include <stdio.h>

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    int frequency[10] = {0}; // Array to store frequency of digits 0-9, initialized to 0

    // Input the elements of the array (assumed to be digits from 0-9)
    printf("Enter the elements of the array (digits from 0-9):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Increment the frequency of the digit
        if (arr[i] >= 0 && arr[i] <= 9) {
            frequency[arr[i]]++;
        } else {
            printf("Invalid input: %d. Please enter digits between 0 and 9.\n", arr[i]);
            return 1;
        }
    }

    // Output the frequency of each digit
    printf("Frequency of each digit:\n");
    for (int i = 0; i <= 9; i++) {
        printf("Digit %d: %d times\n", i, frequency[i]);
    }

    return 0;
}
