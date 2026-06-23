#include <stdio.h>

double media(double x, double y) {
    double media = (x + y) / 2;
    return media;
}

int main() {

    double x, y, media1;
    int opcao = 1;

    while(opcao != 2) {
        if(opcao == 1) {
            scanf("%lf", &x);
        
            while(x < 0 || x > 10) {
                printf("nota invalida\n");
                scanf("%lf", &x);
            }
        
            scanf("%lf", &y);
        
            while(y < 0 || y > 10) {
                printf("nota invalida\n");
                scanf("%lf", &y);
            }
        
            media1 = media(x, y);
        
            printf("media = %.2lf\n", media1);
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &opcao);
        
            while(opcao < 0 || opcao > 2) {
                printf("novo calculo (1-sim 2-nao)\n");
                scanf("%d", &opcao);
            }
        }
    }
    

    return 0;
}
