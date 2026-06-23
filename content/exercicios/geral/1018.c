// 1018 Beecrowd - Cédulas
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores ineteiros para cada cédelua e um valor "n"
    int n, c100, c50, c20, c10, c5, c2, c1;
    // Lendo a variável "n"
    scanf("%d", &n);

    // Calculando a quantidade de notas de cada cédula
    // 100 reis
    c100 = n / 100;
    // 50 reais
    c50 = (n % 100) / 50;
    // 20 reais
    c20 = ((n % 100) % 50) / 20;
    // 10 reais
    c10 = (((n % 100) % 50) % 20) / 10;
    // 5 reais
    c5 = ((((n % 100) % 50) % 20) % 10) / 5;
    // 2 reais
    c2 = (((((n % 100) % 50) % 20) % 10) % 5) / 2;
    // 1 real
    c1 = ((((((n % 100) % 50) % 20) % 10) % 5) % 2) / 1;

    // Exibindo a quantidade de notas de cada cédula conforme solicitado
    // Imprimindo o valor total
    printf("%d\n", n);
    // Imprimindo a quantidade de notas de 100 reais
    printf("%d nota(s) de R$ 100,00\n", c100);
    // Imprimindo a quantidade de notas de 50 reais
    printf("%d nota(s) de R$ 50,00\n", c50);
    // Imprimindo a quantidade de notas de 20 reais
    printf("%d nota(s) de R$ 20,00\n", c20);
    // Imprimindo a quantidade de notas de 10 reais
    printf("%d nota(s) de R$ 10,00\n", c10);
    // Imprimindo a quantidade de notas de 5 reais
    printf("%d nota(s) de R$ 5,00\n", c5);
    // Imprimindo a quantidade de notas de 2 reais
    printf("%d nota(s) de R$ 2,00\n", c2);
    // Imprimindo a quantidade de notas de 1 real
    printf("%d nota(s) de R$ 1,00\n", c1);
  
    return 0;
}
