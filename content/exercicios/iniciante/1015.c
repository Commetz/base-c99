// 1015 Beecrowd - Distância Entre Dois Pontos
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca matemática para a usar a função "pow" e a "sqrt" que calcula a raiz quadrada de um número
#include <math.h>

int main() {

    // Declarando variáveis de valores decimais para as coordenadas dos dois pontos e a distância entre eles
    double x1, y1, x2, y2, distancia;
    // Lendo os valores de cada variável, sendo as coordenadas dos dois pontos
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    // Calculando a distância entre os dois pontos usando a fórmula da distância entre dois pontos no plano cartesiano (d = √((x2 - x1)² + (y2 - y1)²))
    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    // Imprimindo a distância entre os pontos conforme requisitado com 4 casas decimais
    printf("%.4lf\n", distancia);
 
    return 0;
}
