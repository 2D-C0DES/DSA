#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push() {
    if (top == SIZE - 1) printf("Stack Overflow\n");
    else {
        int x;
        printf("Enter element to push: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

void pop() {
    if (top == -1) printf("Stack Underflow\n");
    else printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) printf("Stack is empty\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) push();
        else if (choice == 2) pop();
        else if (choice == 3) display();
        else if (choice == 4) break;
        else printf("Invalid choice\n");
    }
    return 0;
}
