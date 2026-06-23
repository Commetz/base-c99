#include <stdio.h>

int main() {

    int a, b, c; 
    scanf("%d %d %d", &a, &b, &c);

    if(a + (b + c) < 0) {
        printf("%d\n", (a + (b + c)) + 24);
    } else { 
        printf("%d\n", (a + (b + c)) % 24); 
    }

    return 0;
}
