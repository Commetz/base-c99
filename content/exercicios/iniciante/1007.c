// 1007 Beecrowd - Diferença
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando 5 variáveis de valores inteiros, sendo 4 para os números e 1 para a diferença
    int a, b, c, d, diferenca;
    // Lendo os valores de "a", "b", "c" e "d"
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Calculando a diferença entre o produto de "a" e "b" e o produto de "c" e "d"
    diferenca = (a * b) - (c * d);

    // Imprimindo o valor da diferença conforme requisitado
    printf("DIFERENCA = %d\n", diferenca);

    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
