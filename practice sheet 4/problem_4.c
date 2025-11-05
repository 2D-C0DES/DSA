#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top < SIZE - 1) stack[++top] = value;
}

int pop() {
    return (top >= 0) ? stack[top--] : 0;
}

int evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) 
            push(postfix[i] - '0'); // Convert char to int
        else {
            int b = pop();
            int a = pop();
            switch (postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop(); // Final result
}

int main() {
    char postfix[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}
