#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n;
    scanf("%d", &n);

    int x[n], y[n], z[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);      
    }

    for(int i = 0; i < n; i++) {
        double cont = 0, menor = 10000000;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                cont = sqrt(pow(abs(x[i] - x[j]), 2) + pow(abs(y[i] - y[j]), 2) + pow(abs(z[i] - z[j]), 2));

                if(cont < menor) {
                    menor = cont;
                }
            }        
        }

        if(menor <= 20) {
            printf("A\n");
        } else if(menor <= 50) {
            printf("M\n");
        } else {
            printf("B\n");
        }
    }
    
    
    return 0;
}


