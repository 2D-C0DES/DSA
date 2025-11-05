#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top < SIZE - 1) stack[++top] = c;
}

char pop() {
    return (top >= 0) ? stack[top--] : '\0';
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[SIZE];
    int j = 0;
    
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) postfix[j++] = infix[i];
        else if (infix[i] == '(') push(infix[i]);
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    
    while (top != -1) postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
