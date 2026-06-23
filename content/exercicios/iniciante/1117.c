#include <stdio.h>

int main() {

    while(1) {
        double x;
        scanf("%lf", &x);
    
        if(x < 0 || x > 10) {
            printf("nota invalida\n");
        } else {
            while(1) {
                double y;
                scanf("%lf", &y);
            
                if(y < 0 || y > 10) {
                    printf("nota invalida\n");
                } else {
                    printf("media = %.2lf\n", (x + y) / 2);
                    return 0;
                }
            }
        }
    }
}
