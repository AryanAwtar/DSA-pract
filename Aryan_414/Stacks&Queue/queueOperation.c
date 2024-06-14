
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = queue[front++];
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    return item;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(15);
    enqueue(17);
    enqueue(28);
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    return 0;
}
