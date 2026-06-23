#include <stdio.h>

int main() {

    int n, f = 1, i = 0;
    scanf("%d", &n);
    int x = n;
    
    for(; n > 0; n--) {
        f *= x - i;
        i++;
    }
    
    printf("%d\n", f);

    return 0;
}
