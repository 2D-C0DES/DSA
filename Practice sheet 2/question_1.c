#include <stdio.h>

int main() {
    int arr[100], size, element, position, choice;

    printf("Enter the current size of the array (0-100): ");
    scanf("%d", &size);

    if (size < 0 || size > 100) {
        printf("Invalid size.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array operations:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at specific position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    if (choice == 1) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
    } else if (choice == 2) {
        arr[size++] = element;
    } else if (choice == 3) {
        printf("Enter the position to insert: ");
        scanf("%d", &position);
        if (position < 0 || position > size) {
            printf("Invalid position.\n");
            return 1;
        }
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        size++;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}