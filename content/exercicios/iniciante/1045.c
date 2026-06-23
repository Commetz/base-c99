#include <stdio.h>

int main() {
    double a, b, c, temp;

    scanf("%lf %lf %lf", &a, &b, &c);

    if (a < b) { temp = a; a = b; b = temp; }
    if (b < c) { temp = b; b = c; c = temp; }
    if (a < b) { temp = a; a = b; b = temp; }

    if (a >= b + c) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        if (a * a == b * b + c * c) printf("TRIANGULO RETANGULO\n");
        if (a * a > b * b + c * c) printf("TRIANGULO OBTUSANGULO\n");
        if (a * a < b * b + c * c) printf("TRIANGULO ACUTANGULO\n");
        if (a == b && b == c) printf("TRIANGULO EQUILATERO\n");
        if ((a == b && b != c) || (b == c && a != b) || (a == c && b != a)) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }

    return 0;
}

