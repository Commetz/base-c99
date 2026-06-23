#include <stdio.h>
#include <math.h>

int main() {
    int x;

    while (1) {
        scanf("%d", &x);
        if (x == 0) break;

        int maior = pow(2, (x - 1) * 2);
        int largura = 0;

        while (maior > 0) {
            maior /= 10;
            largura++;
        }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                int valor = pow(2, i + j);
                if (j == 0) {
                    printf("%*d", largura, valor);
                } else {
                    printf(" %*d", largura, valor);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

