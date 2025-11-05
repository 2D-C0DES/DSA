#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    int x;
    printf("Enter element to enqueue: ");
    scanf("%d", &x);
    if (front == -1) front = 0; // First element
    queue[++rear] = x;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
    if (front > rear) front = rear = -1; // Reset queue
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
