#include <stdio.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort used by Radix Sort
void countingSort(int arr[], int n, int exp)
{
    int output[n];       // Output array
    int count[10] = {0}; // Count array for digits 0–9

    // Step 1: Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Step 2: Convert count[] to represent actual positions in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Step 3: Build the output array (stable sorting)
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Step 4: Copy sorted numbers back into original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main Radix Sort function
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n); // Find the largest number

    // Apply counting sort to each digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}
