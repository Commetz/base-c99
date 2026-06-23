#include <stdio.h>

int main() {

    int x = 0, y = 1, n;
    scanf("%d", &n);

    if (n == 0) {
        return 0;
    }
    else if(n == 1) {
        printf("0\n");
    }
    else if(n == 2) {
        printf("0 1\n");
    } else if(n > 2) {
        printf("0 1");
        n -= 2;
    }
    
    for(; n > 0; n--) {
        int z = x + y;
        printf(" %d", z);
        x = y;
        y = z;
    }
    
    printf("\n");

    return 0;
}
