// 1021 Beecrowd - Notas e Moedas
// Por Commetz
#include <stdio.h>

int main() {

    double valor;
    scanf("%lf", &valor);

    // Convertendo o valor para centavos para evitar problemas de precisão com números decimais
    int centavos = (int)(valor * 100 + 0.5);

    printf("NOTAS:\n");

    // Calculando a quantidade de notas de 100 reais necessárias e atualizando o valor restante
    int n100 = centavos / 10000;
    centavos %= 10000;
    printf("%d nota(s) de R$ 100.00\n", n100);

    // Calculando a quantidade de notas de 50 reais necessárias e atualizando o valor restante
    int n50 = centavos / 5000;
    centavos %= 5000;
    printf("%d nota(s) de R$ 50.00\n", n50);

    // Calculando a quantidade de notas de 20 reais necessárias e atualizando o valor restante
    int n20 = centavos / 2000;
    centavos %= 2000;
    printf("%d nota(s) de R$ 20.00\n", n20);

    // Calculando a quantidade de notas de 10 reais necessárias e atualizando o valor restante
    int n10 = centavos / 1000;
    centavos %= 1000;
    printf("%d nota(s) de R$ 10.00\n", n10);

    // Calculando a quantidade de notas de 5 reais necessárias e atualizando o valor restante
    int n5 = centavos / 500;
    centavos %= 500;
    printf("%d nota(s) de R$ 5.00\n", n5);

    // Calculando a quantidade de notas de 2 reais necessárias e atualizando o valor restante
    int n2 = centavos / 200;
    centavos %= 200;
    printf("%d nota(s) de R$ 2.00\n", n2);

    printf("MOEDAS:\n");

    // Calculando a quantidade de moedas de 1 real necessárias e atualizando o valor restante
    int m1 = centavos / 100;
    centavos %= 100;
    printf("%d moeda(s) de R$ 1.00\n", m1);

    // Calculando a quantidade de moedas de 50 centavos necessárias e atualizando o valor restante
    int m50 = centavos / 50;
    centavos %= 50;
    printf("%d moeda(s) de R$ 0.50\n", m50);

    // Calculando a quantidade de moedas de 25 centavos necessárias e atualizando o valor restante
    int m25 = centavos / 25;
    centavos %= 25;
    printf("%d moeda(s) de R$ 0.25\n", m25);

    // Calculando a quantidade de moedas de 10 centavos necessárias e atualizando o valor restante
    int m10 = centavos / 10;
    centavos %= 10;
    printf("%d moeda(s) de R$ 0.10\n", m10);

    // Calculando a quantidade de moedas de 5 centavos necessárias e atualizando o valor restante
    int m5 = centavos / 5;
    centavos %= 5;
    printf("%d moeda(s) de R$ 0.05\n", m5);

    // Calculando a quantidade de moedas de 1 centavo necessárias
    int m1cent = centavos;
    printf("%d moeda(s) de R$ 0.01\n", m1cent);

    return 0;
}