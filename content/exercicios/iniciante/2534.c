#include <stdio.h>

void sort(int *v, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int tmp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > tmp; j -= gap)
                v[j] = v[j - gap];
            v[j] = tmp;
        }
}

int main() {

    int n, q;

    while(scanf("%d %d", &n, &q) != EOF) {
        int vetor[n+1];

        for(int i = 0; i < n; i++) {
            scanf("%d", &vetor[i]);
        }

        sort(vetor, n);

        for(int i = 0; i < q; i++) {
            int x;
            scanf("%d", &x);

            printf("%d\n", vetor[n-x]);
        }  
    }
    
    return 0;
}

