#include <stdio.h>

int main() {

    int n, cont = 0, conta = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x; 
        scanf("%d", &x);

        if(x == 1) {
            cont++;
        } 

        conta ++;
    }
    
    printf("%d\n", conta - cont);
    
    return 0;
}   
