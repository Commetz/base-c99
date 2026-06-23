#include <stdio.h>

int main() {

    int n;
    
    while(scanf("%d", &n) != EOF) {
        int cont = 0, op = 1;
        
        for(int i = 1; n > 1; i++) {
            n -= op;
            op *= 2;
            cont = i;
        }
        
        printf("%d\n", cont);
    }   
    
    return 0;
}

