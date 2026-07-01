// 1020 Beecrowd - Idade em Dias
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando as variáveis de valores inteiros "idade_em_dias", "anos", "meses" e "dias" para guardar o resultado da conversão da idade em dias 
    int idade_em_dias, anos, meses, dias;
    // Lendo a variável "idade_em_dias" (idade em dias)
    scanf("%d", &idade_em_dias);

    // Calculando a quantidade de anos, meses e dias a partir da idade total em dias, utilizando a divisão inteira e o operador módulo para obter os valores restantes
    anos = idade_em_dias / 365;
    meses = (idade_em_dias % 365) / 30;
    dias = (idade_em_dias % 365) % 30;

    // Exibindo as quantidades de anos, meses e dias conforme requisitado no formato "anos meses dias"
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);

    return 0;
}
