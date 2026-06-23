#include <stdio.h>

int main() {

    int a, b, c; 
    scanf("%d %d %d", &a, &b, &c);

    if(a + b <= c || b + c <= a || a + c <= b) {
        printf("Invalido\n");
    } else {
        if(a == b && b == c) {
            printf("Valido-Equilatero\n");
        } else if(a == b || b == c || a == c) {
            printf("Valido-Isoceles\n");
        } else {
            printf("Valido-Escaleno\n");
        }

        if(a >= b && a >= c && a*a == b*b + c*c) {
            printf("Retangulo: S\n");
        } else if(b >= a && b >= c & b*b == a*a + c*c) {
            printf("Retangulo: S\n");
        } else if(c >= a && c >= b && c*c == a*a + b*b) {
            printf("Retangulo: S\n");
        } else {
            printf("Retangulo: N\n");
        }
    }
    
    return 0;
}
