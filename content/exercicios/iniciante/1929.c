#include <stdio.h>

int main() {
    
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if(a + b > c && b + c > a && a + c > b) {
        printf("S\n");
    } else if(a + b > d && b + d > a && a + d > b) {
        printf("S\n");
    } else if(b + d > c && c + d > b && b + c > d) {
        printf("S\n");
    } else if(a + d > c && d + c > a && a + c > d) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}
