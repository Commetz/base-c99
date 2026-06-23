// 1013 Beecrowd - O Maior
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros
    int a, b, c, maior1, maior2;
    // Lendo os valores de cada variável
    scanf("%d %d %d", &a, &b, &c);

    // A função "abs" serve para retornar o valor absoluto, transformando números negativos em positivos

    // Usando a fórmula para descobrir o maior valor entra a ou b
    maior1 = (a + b + abs(a - b))/2;
    // Usando a fórmula para descobrir o maior valor entre maior1 e c
    maior2 = (maior1 + c + abs(maior1 - c))/2;

    // Imprimindo os valores das áreas conforme requisitado
    printf("%d eh o maior\n", maior2);
    
    
    return 0;
}
