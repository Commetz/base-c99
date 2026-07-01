// 1013 Beecrowd - O Maior
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca "stdlib.h" para utilizar a função "abs" que retorna o valor absoluto de um número
#include <stdlib.h>

int main() {

    // Declarando variáveis de valores inteiros para os três números e para o maior valor
    int a, b, c, maior1, maior2;
    // Lendo os valores de cada variável, sendo os três números
    scanf("%d %d %d", &a, &b, &c);

    // A função "abs" serve para retornar o valor absoluto, transformando números negativos em positivos, e a fórmula para descobrir o maior valor entre dois números é (a + b + abs(a - b))/2, sendo "a" e "b" os dois números que queremos comparar

    // Usando a fórmula para descobrir o maior valor entra as variáveis "a" e "b"
    maior1 = (a + b + abs(a - b))/2;
    // Usando a fórmula para descobrir o maior valor entre maior1 e "c", que é o maior valor entre "a" e "b"
    maior2 = (maior1 + c + abs(maior1 - c))/2;

    // Imprimindo os valores das áreas conforme requisitado, sendo o maior valor entre os três números
    printf("%d eh o maior\n", maior2);
    
    return 0;
}
