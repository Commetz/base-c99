#include <stdio.h>

int main() {

    char d1[11], d2[11], d3[11];
    scanf("%[^/]/%[^/]/%[^\n]", d1, d2, d3);

    printf("%s/%s/%s\n", d2, d1, d3);
    printf("%s/%s/%s\n", d3, d2, d1);
    printf("%s-%s-%s\n", d1, d2, d3);

    return 0;
}

