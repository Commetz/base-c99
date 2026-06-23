#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int x;
    
    while(1) {
        scanf("%d", &x);
        
        if (x == 0) {
            return 0;
        }
        
        for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= x; j++) {
                
                int valor = abs(i - j) + 1;
                
                if (j == 1) {
                    printf("%3d", valor);
                } else {
                    printf(" %3d", valor);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
