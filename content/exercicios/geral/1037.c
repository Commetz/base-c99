// 1037 Beecrowd - Intervalo
// Por Commetz
#include <stdio.h> 

int main() {

    // Declara a variável que armazenará o valor de entrada
    double valor;
    // Lê o valor digitado pelo usuário
    scanf("%lf", &valor);

    // Verifica se o valor está no intervalo [0,25]
    if (valor >= 0 && valor <= 25) {
        printf("Intervalo [0,25]\n");
    }
    // Verifica se o valor está no intervalo (25,50]
    else if (valor > 25 && valor <= 50) {
        printf("Intervalo (25,50]\n");
    }
    // Verifica se o valor está no intervalo (50,75]
    else if (valor > 50 && valor <= 75) {
        printf("Intervalo (50,75]\n");
    }
    // Verifica se o valor está no intervalo (75,100]
    else if (valor > 75 && valor <= 100) {
        printf("Intervalo (75,100]\n");
    } else { 
        // Caso nenhum caso seja identificado
        printf("Fora de intervalo\n");
    }

    return 0;
}
