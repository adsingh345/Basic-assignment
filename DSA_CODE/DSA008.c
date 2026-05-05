#include <stdio.h>

long long power(int a, int b) {
    if (b == 0)       // base case
        return 1;
    else
        return a * power(a, b - 1);   // recursive call
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%lld", power(a, b));

    return 0;
}
