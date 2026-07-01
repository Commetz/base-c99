// 1004 Beecrowd - Produto Simples
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando três variáveis de valores inteiros
    int a, b, produto;
    // Lendo os valores das duas primeiras variáveis
    scanf("%d %d", &a, &b);
    
    // Afirmando que o valor do "produto" é o produto entre as duas primeiras variáveis
    produto = a * b;

    // Exibindo a mensagem requisitada com o valor da variável "produto" 
    printf("PROD = %d\n", produto);

    // Retornando 0 para indicar que o programa foi executado com sucesso
    return 0;
}
