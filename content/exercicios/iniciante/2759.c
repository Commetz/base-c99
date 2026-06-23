#include <stdio.h>
 
int main() {
 
    char c, d, e;
    scanf("%c %c %c", &c, &d, &e);
    
    printf("A = %c, B = %c, C = %c\n", c, d, e);
    printf("A = %c, B = %c, C = %c\n", d, e, c);
    printf("A = %c, B = %c, C = %c\n", e, c, d);
    
    return 0;
}
