// 1002 Beecrowd - Área Do Círculo
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca matemática para utilizar a função "pow" que calcula a potência de um número
#include <math.h>

int main() {

    // Declarando três variáveis com valores decimais para o raio, a área e o valor de pi
    double raio, area, pi;
    // Lendo o valor do raio
    scanf("%lf", &raio);

    // Afirmando o valor de pi como 3.14159
    pi = 3.14159;
    // Afirmando o valor da área usando a fórmula da área do círculo (A = π * r²)
    area = pi * pow(raio, 2);

    // Exibindo a mensagem requisitada com 4 casas decimais do valor da área
    printf("A=%.4lf\n", area);

    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
