// 1038 Beecrowd - Lanche
// Por Commetz
#include <stdio.h>

int main() {
    
    // Declaração das variáveis inteiras 'a' (código do produto) e 'b' (quantidade)
    int a, b;
    // Leitura dos valores de entrada
    scanf("%d %d", &a, &b);

    // Verifica se o código é 1 (Cachorro Quente) e calcula o total
    if (a == 1) {
        printf("Total: R$ %.2lf\n", b * 4.00);
    }
    // Verifica se o código é 2 (X-Salada) e calcula o total
    else if (a == 2) {
        printf("Total: R$ %.2lf\n", b * 4.50);
    }
    // Verifica se o código é 3 (X-Bacon) e calcula o total
    else if (a == 3) {
        printf("Total: R$ %.2lf\n", b * 5.00);
    }
    // Verifica se o código é 4 (Torrada simples) e calcula o total
    else if (a == 4) {
        printf("Total: R$ %.2lf\n", b * 2.00);
    }
    // Verifica se o código é 5 (Refrigerante) e calcula o total
    else if (a == 5) { 
        printf("Total: R$ %.2lf\n", b * 1.50);
    }

    return 0;
}
