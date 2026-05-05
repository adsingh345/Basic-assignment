#include <stdio.h>

int main() {
    int n;
    // Get the size of the array
    if (scanf("%d", &n) != 1 || n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Handle the first element (always unique)
    printf("%d", arr[0]);

    // Iterate starting from the second element
    for (int i = 1; i < n; i++) {
        // If current element is different from the previous, it's unique
        if (arr[i] != arr[i - 1]) {
            printf(" %d", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
