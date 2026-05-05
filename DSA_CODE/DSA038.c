#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int size() {
    if(front == -1) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if(front == -1) {
        front = rear = 0;
    }
    else if(front > 0) {
        front--;
    }
    else {
        printf("Deque Overflow\n");
        return;
    }
    dq[front] = x;
}

void push_back(int x) {
    if(front == -1) {
        front = rear = 0;
    }
    else if(rear < MAX - 1) {
        rear++;
    }
    else {
        printf("Deque Overflow\n");
        return;
    }
    dq[rear] = x;
}

void pop_front() {
    if(isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if(isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void getFront() {
    if(isEmpty())
        printf("-1\n");
    else
        printf("%d\n", dq[front]);
}

void getBack() {
    if(isEmpty())
        printf("-1\n");
    else
        printf("%d\n", dq[rear]);
}

void display() {
    if(isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%s", op);

        if(strcmp(op,"push_front")==0) {
            scanf("%d",&x);
            push_front(x);
        }

        else if(strcmp(op,"push_back")==0) {
            scanf("%d",&x);
            push_back(x);
        }

        else if(strcmp(op,"pop_front")==0)
            pop_front();

        else if(strcmp(op,"pop_back")==0)
            pop_back();

        else if(strcmp(op,"front")==0)
            getFront();

        else if(strcmp(op,"back")==0)
            getBack();

        else if(strcmp(op,"size")==0)
            printf("%d\n", size());

        else if(strcmp(op,"empty")==0)
            printf("%d\n", isEmpty());
    }

    printf("Final Deque: ");
    display();

    return 0;
}
