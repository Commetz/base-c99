#include <stdio.h>

int main() {

    int n, cont = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);

        if(x >= 10 && x <= 20) {
            cont++;
        }
    }

    printf("%d in\n%d out\n", cont, (n - cont));
    
    return 0;
}   
