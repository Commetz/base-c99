#include <stdio.h>

int main() {
    
    while(1) {
        int m, n, sum = 0;
        scanf("%d %d", &m, &n);
        
        if(m < 1|| n < 1) {
            return 0;
        }
        else if (m > n) {
            for(; n <= m; n++) {
                printf("%d ", n);
                sum += n;
            }
            printf("Sum=%d\n", sum);
        }
        else if (n > m) {
            for(; m <= n; m++) {
                printf("%d ", m);
                sum += m;
            }
            printf("Sum=%d\n", sum);
        }
    }

    return 0;
}
