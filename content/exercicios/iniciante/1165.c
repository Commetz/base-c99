#include <stdio.h>
#include <math.h>

int main() {

    int n;
    scanf("%d", &n);
    
    for(; n > 0; n--) {
        int x, i = 2, nprimo = 0;
        scanf("%d", &x);
        
        for(int i = 2; i < x; i++) {
            if(x % i == 0) {
                nprimo = 1;
            }
        }

        if(nprimo == 1) {
            printf("%d nao eh primo\n", x);
        } else {
            printf("%d eh primo\n", x);
        }
    }

    return 0;
}
