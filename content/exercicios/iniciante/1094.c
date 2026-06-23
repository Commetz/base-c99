#include <stdio.h>

int main () {

    int n;
    double coelho2, rato2, sapo2, cobaia = 0, coelho = 0, rato = 0, sapo = 0;
    scanf("%d", &n);

    for(; n > 0; n--) {
        int x;
        char y;

        scanf("%d %c", &x, &y);
        
        if (y == 'C') {
            coelho += x;
            cobaia += x;
        }
        else if (y == 'R') {
            rato += x;
            cobaia += x;
        }
        else if (y == 'S') {
            sapo += x;
            cobaia += x;
        }
    }
    
    coelho2 = (coelho * 100) / cobaia;
    rato2 = (rato * 100) / cobaia;
    sapo2 = (sapo * 100) / cobaia;

    printf("Total: %.0lf cobaias\n", cobaia);
    printf("Total de coelhos: %.0lf\n", coelho);
    printf("Total de ratos: %.0lf\n", rato);
    printf("Total de sapos: %.0lf\n", sapo);
    printf("Percentual de coelhos: %.2lf %\n", coelho2);
    printf("Percentual de ratos: %.2lf %\n", rato2);
    printf("Percentual de sapos: %.2lf %\n", sapo2);
    
    return 0;
}
