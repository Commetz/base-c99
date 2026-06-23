#include <stdio.h>

int main() {
    
    int x, contador = 0;
    int posicao, y = 0;

    for(int i = 100; i > 0; i--) {
        contador++;
        scanf("%d", &x);
        if (x > y) {
            y = x;
            posicao = contador;
        }
    }

    printf("%d\n%d\n", y, posicao);

    return 0;
}
