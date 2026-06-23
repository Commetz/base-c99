// 1017 Beecrowd - Gasto de Combustível
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros
    int t, v;
    // Declarando variáveis de valores decimais
    double litros;
    // Lendo os valores do tempo e velocidade 
    scanf("%d %d", &t, &v);

    // Calculando o valor em litros
   litros = (t * v) / 12.0;

    // Imprimindo a quantidade de litros necessários
    printf("%.3lf\n", litros);
 
    return 0;
}
