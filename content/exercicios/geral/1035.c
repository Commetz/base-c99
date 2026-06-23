// 1035 Beecrowd - Teste de Seleção 1
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando 4 inteiros para verificar os valores
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Verificando a condição de valores aceitos
    if (b > c && d > a && (c + d) > (a + b) && c > 0 && d > 0 && a % 2 == 0) {
        // Exibindo caso seja o caso
        printf("Valores aceitos\n");
    } else {
        // Exibindo caso não seja o caso
        printf("Valores nao aceitos\n");
    }
    
    return 0;
}
