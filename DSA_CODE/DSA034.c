#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop() {
    if(top == NULL)
        return 0;

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char postfix[100];
    int i = 0;

    fgets(postfix, sizeof(postfix), stdin);

    while(postfix[i] != '\0') {

        if(postfix[i] == ' ') {
            i++;
            continue;
        }

        if(isdigit(postfix[i])) {
            int num = 0;
            while(isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
            continue;
        }

        else {
            int b = pop();
            int a = pop();
            int result;

            switch(postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    printf("%d", pop());

    return 0;
}
