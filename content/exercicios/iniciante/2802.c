#include <stdio.h>

unsigned long long combinacao(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k; // Simetria: C(n, k) == C(n, n-k)

    unsigned long long resultado = 1;
    for (int i = 1; i <= k; ++i) {
        resultado = resultado * (n - k + i) / i;
    }
    return resultado;
}

int main() {

    int n;
    scanf("%d", &n);

    long long valor = 1 + combinacao(n, 2) + combinacao(n, 4);

    printf("%lld\n", valor);
       
    return 0;
}
