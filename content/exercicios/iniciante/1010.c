// 1010 Beecrowd - Cálculo
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros para o código e o número de peças de cada peça
    int codigo_peca1, numero_de_peças1, codigo_peca2, numero_de_peças2;
    // Declarando variáveis de valores decimais para o valor unitário de cada peça e o valor total do pagamento
    double valor_unitario1, valor_unitario2, valor_total;
    // Lendo os valores de cada variável de cada peça, sendo o código, o número de peças e o valor unitário
    scanf("%d %d %lf", &codigo_peca1, &numero_de_peças1, &valor_unitario1);
    scanf("%d %d %lf", &codigo_peca2, &numero_de_peças2, &valor_unitario2);

    // Calculando o valor do pagamento total multiplicando o número de peças pelo valor unitário de cada peça e somando os dois resultados
    valor_total = (numero_de_peças1 * valor_unitario1) + (numero_de_peças2 * valor_unitario2);

    // Imprimindo o valor do pagamento total conforme requisitado com 2 casas decimais
    printf("VALOR A PAGAR: R$ %.2lf\n", valor_total);

    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
