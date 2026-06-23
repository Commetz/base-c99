#include <stdio.h>

int contarDigitos(int numero) {
    if (numero == 0) return 1; 
    if (numero < 0) numero = -numero;

    int count = 0;
    while (numero != 0) {
        numero /= 10;
        count++;
    }
    return count;
}

int main() {

    int a, b, c, d; 
    scanf("%d.%d.%d-%d", &a, &b, &c, &d);

    int na = contarDigitos(a);

    for(int i = na; i < 3; i++) {
        printf("0");
    }

    printf("%d\n", a);

    int nb = contarDigitos(b);

    for(int i = nb; i < 3; i++) {
        printf("0");
    }

    printf("%d\n", b);

    int nc = contarDigitos(c);

    for(int i = nc; i < 3; i++) {
        printf("0");
    }

    printf("%d\n", c);

    int nd = contarDigitos(d);

    for(int i = nd; i < 2; i++) {
        printf("0");
    }

    printf("%d\n", d);

    return 0;
}
