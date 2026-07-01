// 1012 Beecrowd - Área
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca matemática para utilizar a função "pow" que calcula a potência de um número
#include <math.h>

int main() {

    // Declarando variáveis de valores decimais para os três números e as áreas das formas geométricas
    double a, b, c, triangulo, circulo, trapezio, quadrado, retangulo;
    // Lendo os valores de cada variável, sendo os três números
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculando a aréa do triângulo, que tem como base o valor de "a" e como altura o valor de "c"
    triangulo = (a * c) / 2;
    // Calculando a área do círculo, que tem como raio o valor de "c" e o valor de pi como 3.14159
    circulo = 3.14159 * pow(c, 2);
    // Calculando a área do trapézio, que tem como base maior o valor de "a", como base menor o valor de "b" e como altura o valor de "c"
    trapezio = ((a + b) * c) / 2;
    // Calculando a área do quadrado, que tem como lado o valor de "b"
    quadrado = pow(b, 2);
    // Calculando a área do retângulo, que tem como base o valor de "a" e como altura o valor de "b"
    retangulo = a * b;

    // Imprimindo os valores das áreas conforme requisitado com 3 casas decimais
    printf("TRIANGULO: %.3lf\n", triangulo);
    printf("CIRCULO: %.3lf\n", circulo);
    printf("TRAPEZIO: %.3lf\n", trapezio);
    printf("QUADRADO: %.3lf\n", quadrado);
    printf("RETANGULO: %.3lf\n", retangulo);   
    
    return 0;
}
