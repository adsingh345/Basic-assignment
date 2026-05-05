#include <stdio.h>
#include <stdlib.h>

// A simple structure to represent a Hash Map node
struct Node {
    long long sum;
    int index;
    struct Node* next;
};

#define HASH_SIZE 10007

// Function to find or insert sum in the Hash Map
int get_max_len(int arr[], int n) {
    struct Node* hashTable[HASH_SIZE] = {NULL};
    long long currentSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == 0) {
            maxLen = i + 1;
        } else {
            // Hash function for negative values
            int hashIdx = abs((int)(currentSum % HASH_SIZE));
            struct Node* temp = hashTable[hashIdx];
            int found = 0;

            // Search for currentSum in hash table
            while (temp != NULL) {
                if (temp->sum == currentSum) {
                    if (i - temp->index > maxLen) {
                        maxLen = i - temp->index;
                    }
                    found = 1;
                    break;
                }
                temp = temp->next;
            }

            // If not found, insert currentSum with its index
            if (!found) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->sum = currentSum;
                newNode->index = i;
                newNode->next = hashTable[hashIdx];
                hashTable[hashIdx] = newNode;
            }
        }
    }
    return maxLen;
}

int main() {
    int arr[10000];
    int n = 0;

    // Read input until EOF or non-integer
    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    printf("%d\n", get_max_len(arr, n));

    return 0;
}
