#include <stdio.h>

int main() {

    int n, cont = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n + 1; i++) {
        cont += i;
    }
    
    printf("%d\n", cont);
    
    return 0;
}
