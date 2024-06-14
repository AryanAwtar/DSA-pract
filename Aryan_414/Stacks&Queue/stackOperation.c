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
    int x = stack[top];
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    printf("%d popped from stack\n", x);
    top--;
    return x;
}

int main() {
    push(15);
    push(21);
    push(18);
    pop();
    pop();
    pop();
    pop();
    pop();
    
    return 0;
}