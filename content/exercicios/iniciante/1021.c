// 1021 Beecrowd - Notas e Moedas
// Por Commetz
#include <stdio.h>

int main() {

    // Valor decimal do valor
    double valor;
    // Valores inteiros de notas e moedas
    int notas, moedas;

    // Lendo o valor de capital
    scanf("%lf", &valor);

    // Convertendo para centavos para facilitar o cálculo
    int centavos = (int)(valor * 100 + 0.5);

    // Calculando e mostrando quantas notas de 100 reais
    printf("NOTAS:\n");
    notas = centavos / 10000;
    printf("%d nota(s) de R$ 100.00\n", notas);
    centavos %= 10000;

    // Calculando e mostrando quantas notas de 50 reais
    notas = centavos / 5000;
    printf("%d nota(s) de R$ 50.00\n", notas);
    centavos %= 5000;

    // Calculando e mostrando quantas notas de 20 reais
    notas = centavos / 2000;
    printf("%d nota(s) de R$ 20.00\n", notas);
    centavos %= 2000;

    // Calculando e mostrando quantas notas de 10 reais
    notas = centavos / 1000;
    printf("%d nota(s) de R$ 10.00\n", notas);
    centavos %= 1000;

    // Calculando e mostrando quantas notas de 5 reais
    notas = centavos / 500;
    printf("%d nota(s) de R$ 5.00\n", notas);
    centavos %= 500;

    // Calculando e mostrando quantas notas de 2 reais
    notas = centavos / 200;
    printf("%d nota(s) de R$ 2.00\n", notas);
    centavos %= 200;

    // Calculando e mostrando as moedas de 1 real
    printf("MOEDAS:\n");
    moedas = centavos / 100;
    printf("%d moeda(s) de R$ 1.00\n", moedas);
    centavos %= 100;

    // Calculando e mostrando as moedas de 50 centavos
    moedas = centavos / 50;
    printf("%d moeda(s) de R$ 0.50\n", moedas);
    centavos %= 50;

    // Calculando e mostrando as moedas de 25 centavos
    moedas = centavos / 25;
    printf("%d moeda(s) de R$ 0.25\n", moedas);
    centavos %= 25;

    // Calculando e mostrando as moedas de 10 centavos
    moedas = centavos / 10;
    printf("%d moeda(s) de R$ 0.10\n", moedas);
    centavos %= 10;

    // Calculando e mostrando as moedas de 5 centavos
    moedas = centavos / 5;
    printf("%d moeda(s) de R$ 0.05\n", moedas);
    centavos %= 5;

    // Calculando e mostrando as moedas de 1 centavo
    moedas = centavos;
    printf("%d moeda(s) de R$ 0.01\n", moedas);

    return 0;
}
