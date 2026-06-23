#include <stdio.h>

int main() {
    int par[5], impar[5];
    int i, num;
    int p = 0, imp = 0;

    for (i = 0; i < 15; i++) {
        scanf("%d", &num);

        if (num % 2 == 0) {
            par[p] = num;
            p++;
            if (p == 5) {
                for (int j = 0; j < 5; j++) {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                p = 0;
            }
        } else {
            impar[imp] = num;
            imp++;
            if (imp == 5) {
                for (int j = 0; j < 5; j++) {
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                imp = 0;
            }
        }
    }

    // Imprimir os que restaram
    for (int j = 0; j < imp; j++) {
        printf("impar[%d] = %d\n", j, impar[j]);
    }
    for (int j = 0; j < p; j++) {
        printf("par[%d] = %d\n", j, par[j]);
    }

    return 0;
}

