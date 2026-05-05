#include <stdio.h>
#include <stdlib.h>

#define MAX 200

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
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

void verticalOrder(struct Node* root) {

    if(root == NULL)
        return;

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    int columns[200][100];
    int count[200] = {0};

    int offset = 100;

    queue[rear++] = (struct Pair){root, 0};

    while(front < rear) {

        struct Pair temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd + offset;

        columns[hd][count[hd]++] = node->data;

        if(node->left)
            queue[rear++] = (struct Pair){node->left, temp.hd - 1};

        if(node->right)
            queue[rear++] = (struct Pair){node->right, temp.hd + 1};
    }

    for(int i = 0; i < 200; i++) {
        if(count[i] > 0) {
            for(int j = 0; j < count[i]; j++)
                printf("%d ", columns[i][j]);
            printf("\n");
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    verticalOrder(root);

    return 0;
}
