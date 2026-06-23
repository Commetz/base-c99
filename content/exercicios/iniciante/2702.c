#include <stdio.h>

int main() {

    int a, b, c;
    int a1, b1, c1;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &a1, &b1, &c1);
    
    int a2 = a - a1;
    int b2 = b - b1;
    int c2 = c - c1;
    
    int total = 0;
    
    if(a2 < 0) {
        total += a2 * -1;
    }
    
    if(b2 < 0) {
        total += b2 * -1;
    }
    
    if(c2 < 0) {
        total += c2 * -1;
    }
    
    printf("%d\n", total);

	return 0;
}
