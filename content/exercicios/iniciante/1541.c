#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;

    while (1) {
        scanf("%d", &a);
        if (a == 0) break;

        scanf("%d %d", &b, &c);

        int area = a * b;
        int lado = (int)sqrt((area * 100) / c);
        printf("%d\n", lado);
    }

    return 0;
}

