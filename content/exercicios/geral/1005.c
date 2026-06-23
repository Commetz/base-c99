// 1005 Beecrowd - Média 1
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando três variáveis de valores decimais
    double a, b, media;
    // Lendo os valores de "a" e de "b"
    scanf("%lf %lf", &a, &b);

    // Calculando a média conforme os pesos dado pelo exercício 
    media = (a * 3.5 + b * 7.5) / 11;

    // Exibindo o valor da média conforme o requisitado
    printf("MEDIA = %.5lf\n", media);

    return 0;
}
