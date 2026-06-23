// 1010 Beecrowd - Cálculo
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros
    int c1, n1, c2, n2;
    // Declarando variáveis de valores decimais
    double v1, v2, valor;
    // Lendo os valores de cada variável
    scanf("%d %d %lf", &c1, &n1, &v1);
    scanf("%d %d %lf", &c2, &n2, &v2);

    // Calculando o valor do pagamento total
    valor = (n1 * v1) + (n2 * v2);

    // Imprimindo o valor do pagamento total conforme requisitado
    printf("VALOR A PAGAR: R$ %.2lf\n", valor);
    
    return 0;
}
