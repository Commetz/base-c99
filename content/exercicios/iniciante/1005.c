// 1005 Beecrowd - Média 1
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando três variáveis de valores decimais para os dois números e a média
    double a, b, media;
    // Lendo os valores de "a" e de "b"
    scanf("%lf %lf", &a, &b);

    // Calculando a média conforme os pesos dado pelo exercício (3.5 e 7.5) e dividindo pelo somatório dos pesos (11)
    media = (a * 3.5 + b * 7.5) / 11;

    // Exibindo o valor da média conforme o requisito com 5 casas decimais
    printf("MEDIA = %.5lf\n", media);

    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
