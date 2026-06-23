#include <stdio.h>

void decimalParaVetorBinario(unsigned long long decimal, int vetor_binario[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int bit = (decimal >> (tamanho - 1 - i)) & 1ULL;
        vetor_binario[i] = bit;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        unsigned long long x;
        scanf("%llu", &x);

        int bin[50];
        int cont = 0, max = 0;

        decimalParaVetorBinario(x, bin, 50);

        for (int i = 0; i < 50; i++) {
            if (bin[i] == 1) {
                cont++;

                if (cont > max) {
                    max = cont;
                }
            } else {
                cont = 0;
            }
        }

        printf("%d\n", max);
    }

    return 0;
}
