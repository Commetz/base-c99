#include <stdio.h>

int main() {
    int a;
    float b;
    char c;
    char d[51];

    scanf("%d %f %c", &a, &b, &c);
    scanf(" %[^\n]", d);

    printf("%d%.6f%c%s\n", a, b, c, d);
    printf("%d\t%.6f\t%c\t%s\n", a, b, c, d);
    printf("%10d%10.6f%10c%10s\n", a, b, c, d);

    return 0;
}
