// 1007 Beecrowd - Diferença
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando 5 variáveis de valores inteiros
    int a, b, c, d, diferenca;
    // Lendo os valores de "a", "b", "c" e "d"
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Afirmando o valor da diferença 
    diferenca = (a * b) - (c * d);

    // Imprimindo o valor da diferença conforme o requisitado 
    printf("DIFERENCA = %d\n", diferenca);

    return 0;
}
