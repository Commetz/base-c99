// 1030 Beecrowd - A Lenda de Flavious Josephus
// Por Commetz
#include <stdio.h>

// Função para calcular o número de pessoas que sobreviveram
int soldados_vivos (int n, int k) {
    if (n == 1) return 0;
    return (soldados_vivos (n - 1, k) + k) % n;
}

int main() {

    // Declarando as variáveis de valores inteiros 
    int nc, n, k;
    // Lendo a variável de número de casos("nc")
    scanf("%d", &nc);

    // Laço de repetição para ler os valores de n e k
    for (int i = 1; i <= nc; i++) {
        // Lendo os valores de n e k
        scanf("%d %d", &n, &k);
        // Imprimindo o resultado 
        printf("Case %d: %d\n", i, soldados_vivos(n, k) + 1);
    }

    return 0;
}
