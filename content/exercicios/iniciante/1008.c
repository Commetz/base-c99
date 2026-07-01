// 1008 Beecrowd - Salário
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando as variáveis de valores inteiros "número de um funcionário" e "horas trabalhadas"
    int numero, horas_trabalhadas;
    // Declarando as variáveis de valores decimais "valor que recebe por horas" e "salário" para gaurdar o resultado do salário do funcionário
    double valor_hora, salario;
    // Lendo as 3 variáveis "numero", "horas_trabalhadas" e "valor_hora";
    scanf("%d %d %lf", &numero, &horas_trabalhadas, &valor_hora);

    // Calculando o salário do funcionário multiplicando o valor que recebe por hora pelas horas trabalhadas
    salario = valor_hora * horas_trabalhadas;

    // Exibindo o número do funcionário
    printf("NUMBER = %d\n", numero);
    // Exibindo o salário do funcionário
    printf("SALARY = U$ %.2lf\n", salario);

    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
