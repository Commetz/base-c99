#include <stdio.h>

int main() {
    
    int x;
    
    while(scanf("%d", &x) != EOF) {
        
        for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= x; j++) {
                
                int valor = abs(j - i) + 1;
                
                if (j + i == x + 1) {
                    printf("2");
                }
                else if (j == i) {
                    printf("1");
                } else {
                    printf("3");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
