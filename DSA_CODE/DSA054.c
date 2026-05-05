#include <stdio.h>
#include <stdlib.h>

#define MAX 200

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct Node* buildTree(int arr[], int n, int i) {
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

void zigzagTraversal(struct Node* root) {

    if(root == NULL)
        return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    int leftToRight = 1;

    queue[rear++] = root;

    while(front < rear) {

        int size = rear - front;
        int level[size];

        for(int i = 0; i < size; i++) {

            struct Node* node = queue[front++];

            int index;
            if(leftToRight)
                index = i;
            else
                index = size - i - 1;

            level[index] = node->data;

            if(node->left)
                queue[rear++] = node->left;

            if(node->right)
                queue[rear++] = node->right;
        }

        for(int i = 0; i < size; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    zigzagTraversal(root);

    return 0;
}
