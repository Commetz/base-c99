#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    
    for(; n > 0; n--) {
        int x, y = 0;
        scanf("%d", &x);
        
        for(int i = x - 1; i > 0; i--) {
            if(x % i == 0) {
                y += i;
            }
        }

        if (y == x) {
            printf("%d eh perfeito\n", x);
        } else {
            printf("%d nao eh perfeito\n", x);
        }
    }

    return 0;
}
