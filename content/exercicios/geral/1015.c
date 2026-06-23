// 1015 Beecrowd - Distância Entre Dois Pontos
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca matemática para a usar a função "pow" e a "sqrt" que calcula a raiz quadrada de um número
#include <math.h>

int main() {

    // Declarando variáveis de valores decimais
    double xa, ya, xb, yb, distancia;
    // Lendo os valores de cada variável
    scanf("%lf %lf %lf %lf", &xa, &ya, &xb, &yb);

    // Calculando a distância entre os dois pontos
    distancia = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    
    // Imprimindo a distância entre os pontos conforme requisitado
    printf("%.4lf\n", distancia);
 
    return 0;
}
