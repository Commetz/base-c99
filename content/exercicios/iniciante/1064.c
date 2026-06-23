#include <stdio.h>

int main() {

    double a, cont = 0, n = 0;

    for(int i = 0; i < 6; i++) {
        scanf("%lf", &a);

        if(a >= 0) {
            cont += a;
            n++;
        }
    }

    double media = cont / n;

    printf("%.0lf valores positivos\n%.1lf\n", n, media);
    
    return 0;
}


