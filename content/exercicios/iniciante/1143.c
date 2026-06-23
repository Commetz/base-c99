#include <stdio.h>

int main() {

    int n, x = 1;
    scanf("%d", &n);
    
    for(; n > 0; n--) {
        printf("%d %d %d\n", x, x*x, x*x*x);
        x++;
    }

    return 0;
}
