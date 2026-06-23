#include <stdio.h>

int main() {

    int n;
    
    while(scanf("%d", &n) != EOF) {
        double menor = 12.00; 
        for(int i = 0; i < n; i++) {
            double x;
            scanf("%lf", &x);

            if(x < menor) {
                menor = x;
            }
        }

        printf("%.2lf\n", menor);
    }
    
    return 0;
}
