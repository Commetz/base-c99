#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x; 
        scanf("%d", &x);

        if(x > 8000) {
            printf("Mais de 8000!\n");
        } else {
            printf("Inseto!\n");
        }
    }
    
    return 0;
}
