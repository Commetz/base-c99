// 1018 Beecrowd - Cédulas
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando a variável de valor inteiro "valor" para guardar o valor a ser convertido em cédulas
    int valor;
    scanf("%d", &valor);
    // Imprimindo o valor a ser convertido em cédulas conforme requisitado
    printf("%d\n", valor);

    // Calculando a quantidade de cédulas de 100 reais necessárias para cada valor disponível e atualizando o valor restante a ser sacado
    int c100 = valor / 100;
    valor %= 100;
    // Imprimindo a quantidade de cédulas de 100 reais conforme requisitado
    printf("%d nota(s) de R$ 100,00\n", c100);

    // Calculando a quantidade de cédulas de 50 reais necessárias para cada valor disponível e atualizando o valor restante a ser sacado
    int c50 = valor / 50;
    valor %= 50;
    // Imprimindo a quantidade de cédulas de 50 reais conforme requisitado
    printf("%d nota(s) de R$ 50,00\n", c50);

    // Calculando a quantidade de cédulas de 20 reais necessárias para cada valor disponível e atualizando o valor restante a ser sacado
    int c20 = valor / 20;
    valor %= 20;
    // Imprimindo a quantidade de cédulas de 20 reais conforme requisitado
    printf("%d nota(s) de R$ 20,00\n", c20);

    // Calculando a quantidade de cédulas de 10 reais necessárias para cada valor disponível e atualizando o valor restante a ser sacado
    int c10 = valor / 10;
    valor %= 10;
    // Imprimindo a quantidade de cédulas de 10 reais conforme requisitado
    printf("%d nota(s) de R$ 10,00\n", c10);

    // Calculando a quantidade de cédulas de 5 reais necessárias para cada valor disponível e atualizando o valor restante a ser sacado
    int c5 = valor / 5;
    valor %= 5;
    // Imprimindo a quantidade de cédulas de 5 reais conforme requisitado
    printf("%d nota(s) de R$ 5,00\n", c5);

    // Calculando a quantidade de cédulas de 2 reais necessárias para cada valor disponível e atualizando o valor restante a ser sacado
    int c2 = valor / 2;
    valor %= 2;
    // Imprimindo a quantidade de cédulas de 2 reais conforme requisitado
    printf("%d nota(s) de R$ 2,00\n", c2);

    // Calculando a quantidade de cédulas de 1 real necessárias para cada valor disponível e atualizando o valor restante a ser sacado
    int c1 = valor;
    // Imprimindo a quantidade de cédulas de 1 real conforme requisitado
    printf("%d nota(s) de R$ 1,00\n", c1);

    return 0;
}