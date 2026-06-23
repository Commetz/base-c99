#include <stdio.h>
#include <stdlib.h>

int cmp_ll(const void *a, const void *b) {
    long long x = *(long long*)a, y = *(long long*)b;
    return (x > y) - (x < y);
}

/*
 * Retorna Qj * 4 (inteiro), onde pos = j*(n+1)/4.
 * k = floor(pos), r = j*(n+1) mod 4  (fracao = r/4)
 * Q*4 = 4*X[k-1] + r*(X[k] - X[k-1])
 */
long long quartil_x4(long long *arr, int n, int j) {
    long long num = (long long)j * (n + 1);
    int k = (int)(num / 4);
    int r = (int)(num % 4);

    if (k < 1) return 4LL * arr[0];
    if (k >= n) return 4LL * arr[n - 1];

    return 4LL * arr[k - 1] + (long long)r * (arr[k] - arr[k - 1]);
}

int main(void) {
    int n;
    long long v;

    while (scanf("%d %lld", &n, &v) == 2) {
        long long *arr = malloc((size_t)n * sizeof(long long));
        for (int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);

        qsort(arr, n, sizeof(long long), cmp_ll);

        long long q1x4 = quartil_x4(arr, n, 1);
        long long q3x4 = quartil_x4(arr, n, 3);
        long long iqrx4 = q3x4 - q1x4;  /* IQR * 4 */

        /*
         * Limites com fator 0.5 (conforme juiz do beecrowd):
         * lim_inf = Q1 - 0.5*IQR  =>  lim_inf*8 = 2*q1x4 - iqrx4
         * lim_sup = Q3 + 0.5*IQR  =>  lim_sup*8 = 2*q3x4 + iqrx4
         *
         * x eh outlier se: 8*x < lim_inf*8  OU  8*x > lim_sup*8
         */
        long long lim_inf_x8 = 2LL * q1x4 - iqrx4;
        long long lim_sup_x8 = 2LL * q3x4 + iqrx4;

        long long outliers = 0;
        for (int i = 0; i < n; i++) {
            long long x8 = 8LL * arr[i];
            if (x8 < lim_inf_x8 || x8 > lim_sup_x8)
                outliers++;
        }

        printf("%lld\n", outliers * v);
        free(arr);
    }

    return 0;
}
