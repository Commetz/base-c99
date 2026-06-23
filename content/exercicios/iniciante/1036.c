// 1036 Beecrowd - Fórmula de Bhaskara
// Por Commetz
#include <stdio.h>
// Biblioteca para funções matemáticas "pow" e "sqrt"
#include <math.h>

int main() {

    // Declaração das variáveis dos coeficientes da equação de segundo grau
    double a, b, c;
    // Variáveis para armazenar as raízes e o delta
    double r1, r2, delta;
    // Lê os coeficientes a, b e c do usuário
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calcula o valor do delta (b² - 4ac)
    delta = pow(b, 2) - 4 * a * c;

    // Verifica se é impossível calcular as raízes (delta negativo ou a igual a zero)
    if (delta < 0 || a == 0) {
        // Exibe mensagem de erro
        printf("Impossivel calcular\n");
    } else {
        // Calcula a primeira raiz
        r1 = (-b + sqrt(delta)) / (2 * a);  
        // Calcula a segunda raiz
        r2 = (-b - sqrt(delta)) / (2 * a); 

        // Exibe a primeira raiz com 5 casas decimais
        printf("R1 = %.5lf\n", r1);  
        // Exibe a segunda raiz com 5 casas decimais
        printf("R2 = %.5lf\n", r2);  
    }

    return 0;  
}
