#include <stdio.h>

int menor (int a, int b, int c, int d) {
    if (a <= b && a <= c && a <= d) {
        return a;
    }
    if (b <= a && b <= c && b <= d) {
        return b;
    }
    if (c <= a && c <= b && c <= d) {
        return c;
    }
    if (d <= a && d <= b && d <= c) {
        return d;
    }
}

int main() {
    
    int x;
    
    while(1) {
        scanf("%d", &x);
        
        if (x == 0) {
            return 0;
        }
        
        for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= x; j++) {
                int cima = i;
                int esquerda = j;
                int baixo = x - i + 1;
                int direita = x - j + 1;
                
                int valor = menor(cima, esquerda, baixo, direita);
                
                if (j == 1) {
                    printf("%3d", valor);
                } else {
                    printf(" %3d", valor);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
