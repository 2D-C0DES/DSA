#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Initialize hash table with -1 to represent empty slots
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

// Hash function to get the index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert function with linear probing for collision resolution
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {  // Collision detected
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) {     // Table is full
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

// Search function to find a key using linear probing
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;  // Key found
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex)  // Came back to starting point
            break;
    }
    return -1; // Key not found
}

// Display the hash table
void displayTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("Index %d: %d\n", i, hashTable[i]);
}

int main() {
    int choice, value;

    initializeTable();

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                int index = search(value);
                if (index != -1)
                    printf("Value %d found at index %d\n", value, index);
                else
                    printf("Value %d not found\n", value);
                break;
            case 3:
                displayTable();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
