#include <stdio.h>

int main() {

    int cont = 0;

    for (int i = 1; i <= 6; i++) {
        double a;
        scanf("%lf", &a);

        if (a > 0) {
            cont++;
        }
    }

    printf("%d valores positivos\n", cont);

    return 0;
}

