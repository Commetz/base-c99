// 1035 Beecrowd - Teste de Seleção 1
// Por Commetz
#include <stdio.h>

int main() {

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Verificando a condição de valores aceitos, sendo que "b" deve ser maior que "c", "d" deve ser maior que "a", a soma de "c" e "d" deve ser maior que a soma de "a" e "b", "c" e "d" devem ser positivos e "a" deve ser par
    if (b > c && d > a && (c + d) > (a + b) && c > 0 && d > 0 && a % 2 == 0) {
        // Exibindo caso seja o caso
        printf("Valores aceitos\n");
    } else {
        // Exibindo caso não seja o caso
        printf("Valores nao aceitos\n");
    }
    
    return 0;
}
