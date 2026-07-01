// 1014 Beecrowd - Consumo
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros para a distância total percorrida
    int distancia_total_percorrida;
    // Declarando variáveis de valores decimais para o combustível gasto total e o consumo médio de gasolina
    double combustivel_gasto_total, consumo;
    // Lendo os valores de cada variável, sendo a distância total percorrida e o combustível gasto total
    scanf("%d %lf", &distancia_total_percorrida, &combustivel_gasto_total);

    // Calculando o consumo médio de gasolina dividindo a distância total percorrida pelo combustível gasto total
    consumo = distancia_total_percorrida / combustivel_gasto_total;
    
    // Imprimindo o valor do consumo médio de gasolina conforme requisitado com 3 casas decimais
    printf("%.3lf km/l\n", consumo);
 
    return 0;
}
