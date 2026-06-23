#include <stdio.h>

int main() {
    
    
    int x;
    double soma = 0, contador = 0;

    while(1) {
        scanf("%d", &x);

        if(x < 0) {
            break;
        }
        
        soma += x;
        contador++;
    }

    printf("%.2lf\n", soma / contador);

    return 0;
}
