// 1028 Beecrowd - Figurinhas
// Por Commetz
#include <stdio.h>

// Função Principal para resolver o problema
int calcularMDC(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    
    int N;
    scanf("%d", &N); 

    // Laço de repetição para casos de entrada
    for (int i = 0; i < N; i++) {
        int F1, F2;
        scanf("%d %d", &F1, &F2); 
        // Calcula o MDC entre F1 e F2
        int resultado = calcularMDC(F1, F2); 
        // Imprime o resultado
        printf("%d\n", resultado);
    }

    return 0;
}
