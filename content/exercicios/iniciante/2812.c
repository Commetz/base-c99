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

int impares(int *v, int n) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] % 2 != 0) {
            v[j] = v[i];
            j++;
        }
    }
    return j;
}

int main() {

    int n;
    scanf("%d", &n);

    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        int v[x+1];

        for(int j = 0; j < x; j++) {
            scanf("%d", &v[i]);
        }

        x = impares(v, x);
        sort(v, x);

        int z = x - 1, w = 0;
        for(int j = 0; j < x;) {
            if(z == w) {
                break;
            } else {
                printf("%d ", v[z]);
                j++;
                z--;
            }

            if(w == z) {
                break;
            } else {
                printf("%d ",v[w]);
                j++;
                w++;
            }
        }

        printf("\n\n");

    }
    
    return 0;
}

