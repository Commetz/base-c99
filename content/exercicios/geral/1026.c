// 1026 Beecrowd - Carrega ou não Carrega?
// Por Commetz
#include <stdio.h>

int main() {
    
    unsigned int a, b;
    
    // Lendo até o fim do arquivo (EOF)
    while (scanf("%u %u", &a, &b) != EOF) {
        // Realizando a soma bit a bit sem considerar o carry
         unsigned int resultado = a ^ b;
        // Exibindo o resultado
        printf("%u\n", resultado);
    }
    
    return 0;
}
