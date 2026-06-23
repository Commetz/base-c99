// 1020 Beecrowd - Idade em Dias
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando as variáveis de valores inteiros 
    int i, a, m, d;
    // Lendo a variável "i" (idade)
    scanf("%d", &i);

    // Calculando a quantidade de anos, meses e dias
    a = i / 365;
    m = (i % 365) / 30;
    d = (i % 365) % 30;

    // Exibindo as quantidades de anos, meses e dias
    printf("%d ano(s)\n", a);
    printf("%d mes(es)\n", m);
    printf("%d dia(s)\n", d);
  
    return 0;
}
