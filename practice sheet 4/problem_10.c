#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    if (!head) {
        head = newNode;
        newNode->next = head; // Point to itself
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head; // Circular link
    }
}

void delete(int value) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node *current = head, *prev = NULL;
    do {
        if (current->data == value) {
            if (current == head) { // Deleting head
                if (head->next == head) { // Only one node
                    free(head);
                    head = NULL;
                } else {
                    struct Node* tail = head;
                    while (tail->next != head) tail = tail->next;
                    tail->next = head->next;
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
            } else {
                prev->next = current->next;
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);
    printf("Value not found\n");
}

void display() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to head)\n");
}

struct Node* search(int value) {
    if (!head) return NULL;
    struct Node* current = head;
    do {
        if (current->data == value) return current;
        current = current->next;
    } while (current != head);
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
