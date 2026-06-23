// 1014 Beecrowd - Consumo
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros
    int x;
    // Declarando variáveis de valores decimais
    double y, consumo;
    // Lendo os valores de cada variável
    scanf("%d %lf", &x, &y);

    // Calculando o consumo
    consumo = x / y;
    
    // Imprimindo o valor do consumo médio de gasolina 
    printf("%.3lf km/l\n", consumo);
 
    return 0;
}
