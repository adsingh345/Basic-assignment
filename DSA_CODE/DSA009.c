#include <stdio.h>
#include <string.h>

void reverse(char str[], int index) {
    if (index < 0)      // base case
        return;

    printf("%c", str[index]);   // print current character
    reverse(str, index - 1);    // recursive call
}

int main() {
    char str[100];

    scanf("%s", str);           // input string
    int len = strlen(str);

    reverse(str, len - 1);      // start from last index

    return 0;
}
