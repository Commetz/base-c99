#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    
    for(; n > 0; n--) {
        int pa, pb, anos = 0;
        double g1, g2, tg1, tg2;
        scanf("%d %d", &pa, &pb);
        scanf("%lf %lf", &g1, &g2);
        
        tg1 = g1 / 100;
        tg2 = g2 / 100;

        while(1) {
            if(anos > 100) {
                printf("Mais de 1 seculo.\n");
                break;
            }
            if (pa > pb) {
                printf("%d anos.\n", anos);
                break;
            }

            pa += tg1 * pa;
            pb += tg2 * pb;
            anos++;
        }
    }

    return 0;
}
