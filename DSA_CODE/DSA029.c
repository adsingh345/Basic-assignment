#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newnode;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct Node* rotateRight(struct Node* head, int n, int k) {
    if(head == NULL || k == 0)
        return head;

    struct Node* temp = head;

    /* Find last node */
    while(temp->next != NULL)
        temp = temp->next;

    /* Make circular */
    temp->next = head;

    k = k % n;
    int steps = n - k;

    temp = head;
    for(int i = 1; i < steps; i++)
        temp = temp->next;

    /* New head */
    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, n, k);

    printList(head);

    return 0;
}
