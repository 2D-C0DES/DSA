#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct Deque* createDeque() {
    struct Deque* deque = malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

void addFront(struct Deque* deque, int value) {
    struct Node* newNode = createNode(value);
    if (!deque->front) deque->front = deque->rear = newNode;
    else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void addRear(struct Deque* deque, int value) {
    struct Node* newNode = createNode(value);
    if (!deque->rear) deque->front = deque->rear = newNode;
    else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int removeFront(struct Deque* deque) {
    if (!deque->front) return -1;
    struct Node* temp = deque->front;
    int value = temp->data;
    deque->front = deque->front->next;
    if (deque->front) deque->front->prev = NULL;
    else deque->rear = NULL; // Deque is empty
    free(temp);
    return value;
}

int removeRear(struct Deque* deque) {
    if (!deque->rear) return -1;
    struct Node* temp = deque->rear;
    int value = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear) deque->rear->next = NULL;
    else deque->front = NULL; // Deque is empty
    free(temp);
    return value;
}

void display(struct Deque* deque) {
    if (!deque->front) { printf("Deque is empty\n"); return; }
    for (struct Node* curr = deque->front; curr; curr = curr->next)
        printf("%d ", curr->data);
    printf("\n");
}

int main() {
    struct Deque* deque = createDeque();
    int choice, value;
    while (1) {
        printf("\n1. Add Front\n2. Add Rear\n3. Remove Front\n4. Remove Rear\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) { printf("Enter value: "); scanf("%d", &value); addFront(deque, value); }
        else if (choice == 2) { printf("Enter value: "); scanf("%d", &value); addRear(deque, value); }
        else if (choice == 3) { value = removeFront(deque); if (value != -1) printf("Removed from front: %d\n", value); }
        else if (choice == 4) { value = removeRear(deque); if (value != -1) printf("Removed from rear: %d\n", value); }
        else if (choice == 5) display(deque);
        else if (choice == 6) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
