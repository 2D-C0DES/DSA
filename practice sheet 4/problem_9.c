#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head) head->prev = newNode;
    head = newNode;
}

void delete(int value) {
    struct Node* current = head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (!current) {
        printf("Value not found\n");
        return;
    }
    if (current->prev) current->prev->next = current->next;
    else head = current->next; // Deleting head
    if (current->next) current->next->prev = current->prev;
    free(current);
}

void display() {
    struct Node* current = head;
    if (!current) { printf("List is empty\n"); return; }
    while (current) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* search(int value) {
    struct Node* current = head;
    while (current) {
        if (current->data == value) return current;
        current = current->next;
    }
    return NULL;
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2: 
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3: 
                display();
                break;
            case 4: 
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = search(value);
                printf(result ? "Found: %d\n" : "Not found\n", value);
                break;
            case 5: 
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}
