// 1006 Beecrowd - Média 2
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando três variáveis de valores decimais para os três números e a média
    double a, b, c, media;
    // Lendo os valores de "a", "b" e "c"
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculando a média conforme os pesos dado pelo exercício (2, 3 e 5) e dividindo pelo somatório dos pesos (10)
    media = (a * 2 + b * 3 + c * 5) / 10;

    // Exibindo o valor da média conforme o requisito com 1 casa decimal
    printf("MEDIA = %.1lf\n", media);

    
    return 0;
}
