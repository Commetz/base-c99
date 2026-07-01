// 1011 Beecrowd - Esfera
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca matemática para utilizar a função "pow" que calcula a potência de um número
#include <math.h>

int main() {

    // Declarando variável de valor inteiro para o raio da esfera
    int raio;
    // Declarando variáveis de valores decimais para o valor de pi e o volume da esfera
    double pi, volume;
    // Lendo os valores de cada variável, sendo o raio da esfera
    scanf("%d", &raio);

    // Afirmando o valor de pi como 3.14159
    pi = 3.14159;
    // Calculando o valor do volume da esfera usando a fórmula do volume da esfera (V = 4/3 * π * r³)
    volume = 4.0/3.0 * pi * pow(raio, 3);

    // Imprimindo o valor do volume da esfera conforme requisitado com 3 casas decimais
    printf("VOLUME = %.3lf\n", volume);
    
    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
