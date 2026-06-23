#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n) {
        int m = 2 * n;
        long long x[20005];

        for (int i = 0; i < m; i++) {
            scanf("%lld", &x[i]);
        }

        long long maior = x[0] + x[m - 1];
        long long menor = maior;

        for (int i = 0; i < n; i++) {
            long long soma = x[i] + x[m - 1 - i];

            if (soma > maior) maior = soma;
            if (soma < menor) menor = soma;
        }

        printf("%lld %lld\n", maior, menor);
    }

    return 0;
}
