// 1017 Beecrowd - Gasto de Combustível
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros para o tempo gasto e a velocidade média
    int tempo_gasto, velocidade_media;
    // Declarando variáveis de valores decimais para o valor em litros
    double litros;
    // Lendo os valores do tempo e velocidade média do carro
    scanf("%d %d", &tempo_gasto, &velocidade_media);

    // Calculando o valor em litros usando a fórmula (tempo_gasto * velocidade_media) / 12.0, sendo que o carro consome 1 litro de combustível a cada 12 km
    litros = (tempo_gasto * velocidade_media) / 12.0;

    // Imprimindo a quantidade de litros conforme requisitado com 3 casas decimais
    printf("%.3lf\n", litros);
 
    return 0;
}
