#include <stdio.h>

int main() {

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n, k, cont = 0;
        scanf("%d %d", &n, &k);

        if(n < k) {
            cont = n;
        } else {
            for(int j = 0; n >= 0; j++) {
                if(n - k >= 0) {
                    n -= k;
                    cont++;
                } else {
                    break;
                }
            }
            cont += n;
        }

        printf("%d\n", cont);
    }
    
    
    return 0;
}   
