#include <stdio.h>

int main() {

    long long n, roubados = 0;
    scanf("%lld", &n);

    long long visitado = 0, total = 0, v[n];

    for(int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        total += v[i];
    }
    
    int i = 0;
    
    while(i >= 0 && i < n) {
        long long atual = v[i];

        if(v[i] > 0) {
            roubados++;
            v[i]--;
        }
        
        if(visitado <= i) {
            visitado = i;
        }

        if(atual % 2 == 0) {
            i--;
        } else {
            i++;
        }
    }

    printf("%lld %lld\n", visitado + 1, total - roubados);
    
    return 0;
}

