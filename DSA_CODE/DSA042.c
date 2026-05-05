#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x) {
    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue() {
    int val = queue[front];

    if(front == rear)
        front = rear = -1;
    else
        front++;

    return val;
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int N, x;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    while(front != -1) {
        push(dequeue());
    }

    while(top != -1) {
        enqueue(pop());
    }

    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
