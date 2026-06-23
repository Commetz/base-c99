#include <stdio.h>

int main() {

    char alfabeto[27];
    
    
    while(scanf("%s", alfabeto) != EOF) {
    
        int n;
        scanf("%d", &n);
    
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
    
            printf("%c", alfabeto[x-1]);
        }
        
        printf("\n");
    }
    
    return 0;
}

