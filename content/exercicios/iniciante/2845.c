#include <stdio.h>

int main() {

    int n, maior = 0,menor = 10000000;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if(x > maior) {
            maior = x;
        }

        if(x < menor) {
            menor = x;
        }
    }
    
    printf("%d\n", maior + menor);
    
    return 0;
}
