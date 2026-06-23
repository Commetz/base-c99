// 1012 Beecrowd - Área
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca matemática 
#include <math.h>

int main() {

    // Declarando variáveis de valores decimais
    double a, b, c, triangulo, circulo, trapezio, quadrado, retangulo;
    // Lendo os valores de cada variável
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculando a área de cada forma geometrica
    triangulo = (a * c) / 2;
    circulo = 3.14159 * pow(c, 2);
    trapezio = ((a + b) * c) / 2;
    quadrado = pow(b, 2);
    retangulo = a * b;

    // Imprimindo os valores das áreas conforme requisitado
    printf("TRIANGULO: %.3lf\n", triangulo);
    printf("CIRCULO: %.3lf\n", circulo);
    printf("TRAPEZIO: %.3lf\n", trapezio);
    printf("QUADRADO: %.3lf\n", quadrado);
    printf("RETANGULO: %.3lf\n", retangulo);   
    
    return 0;
}
