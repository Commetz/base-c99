// 1002 Beecrowd - Área Do Círculo
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando três variáveis com valores decimais
    double raio, area, pi;
    // Lendo o valor do raio
    scanf("%lf", &raio);

    // Afirmando o valor de pi
    pi = 3.14159;
    // Afirmando o valor da área usando a fórmula da área do círculo 
    area = pi * (raio * raio);

    // Exibindo a mensagem requisitada com 4 casas decimais do valor da área
    printf("A=%.4lf\n", area);

    return 0;
}
