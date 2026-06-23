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

    int n, m, cont = 0;
    scanf("%d %d", &n, &m);

    int x[n+1];

    for(int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    sort(x, n);
        
    for(int i = n - 1; i >= 0; i--) {
        if(x[i] >= x[n - m]) {
            cont++;
        }
    }
     
    printf("%d\n", cont);
    
    return 0;
}

