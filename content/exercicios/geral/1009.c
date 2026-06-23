// 1009 Beecrowd - Salário Com Bônus
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variável de caracter "nome"
    char n[11];
    // Declarando variáveis de valores decimais
    double s, v, b, sf;
    // Lendo os valores do "nome", sálario("s") e das vendas("v")
    scanf("%s %lf %lf", n, &s, &v);

    // Calculando o valor do bônus
    b = (v * 15/100);
    // Calculando o valor do sálario final
    sf = s + b;

    // Imprimindo o valor do sálario final
    printf("TOTAL = R$ %.2lf\n", sf);
    
    return 0;
}
