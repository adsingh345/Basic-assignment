#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    int flag = 1;

    // Read matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check identity matrix condition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(a[i][j] != 1)
                    flag = 0;
            } 
            else {
                if(a[i][j] != 0)
                    flag = 0;
            }
        }
    }

    if(flag)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
