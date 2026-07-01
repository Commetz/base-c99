// 1009 Beecrowd - Salário Com Bônus
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variável de caracter "nome" com 11 caracteres para guardar o nome do funcionário
    char nome[11];
    // Declarando variáveis de valores decimais para o sálario fixo, montante de vendas, bônus e sálario final
    double salario_fixo, montante_vendas, bonus, salario_final;
    // Lendo os valores do "nome", sálario fixo e montante de vendas do funcionário
    scanf("%s %lf %lf", nome, &salario_fixo, &montante_vendas);

    // Calculando o valor do bônus do funcionário multiplicando o montante de vendas por 15% (15/100)
    bonus = (montante_vendas * 15/100);
    // Calculando o valor do sálario final do funcionário somando o sálario fixo com o valor do bônus
    salario_final = salario_fixo + bonus;

    // Imprimindo o valor do sálario final conforme requisitado com 2 casas decimais
    printf("TOTAL = R$ %.2lf\n", salario_final);
    
    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
