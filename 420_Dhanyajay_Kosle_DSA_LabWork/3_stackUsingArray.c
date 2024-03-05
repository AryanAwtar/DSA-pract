//Stack operations
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int main() {
    push(5);
    push(10);
    push(15);
    printf("Top element of the stack: %d\n", peek());
    printf("%d popped from stack\n", pop());
    return 0;
}
