// 1036 Beecrowd - Fórmula de Bhaskara
// Por Commetz
#include <stdio.h>
#include <math.h>

int main() {

    double a, b, c;
    double raiz1, raiz2, delta;
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calcula o valor do delta usando a fórmula delta = b² - 4ac
    delta = pow(b, 2) - 4 * a * c;

    // Verifica se é impossível calcular as raízes, ou seja, se delta é negativo ou se "a" é igual a zero
    if (delta < 0 || a == 0) {
        // Exibe mensagem de erro caso seja impossível calcular as raízes
        printf("Impossivel calcular\n");
    // Caso contrário, calcula as raízes usando a fórmula de Bhaskara
    } else {
        // Calcula a primeira raiz usando a fórmula x1 = (-b + √delta) / (2a)
        raiz1 = (-b + sqrt(delta)) / (2 * a);  
        // Calcula a segunda raiz usando a fórmula x2 = (-b - √delta) / (2a)
        raiz2 = (-b - sqrt(delta)) / (2 * a); 

        printf("R1 = %.5lf\n", raiz1);  
        printf("R2 = %.5lf\n", raiz2);  
    }

    return 0;  
}
