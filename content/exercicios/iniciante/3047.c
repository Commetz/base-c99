#include <stdio.h>

int main() {

    int m, a, b;
    scanf("%d %d %d", &m, &a, &b);

    int c = m - a - b;

    if(a >= b && a >= c) {
        printf("%d\n", a);
    } else if(b >= a && b >= c) {
        printf("%d\n", b);
    } else if(c >= a && c >= b) {
        printf("%d\n", c);
    }
    
    return 0;
}
