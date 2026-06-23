#include <stdio.h>

int main() {
    
    int m, n, k = 1;
    scanf("%d", &m);
    
    while(m != 0) {
        int cont = 0;
        
        for(int i = 0; i < m; i++) {
            scanf("%d", &n);
            cont += n;
        }
        
        printf("Teste %d\n%d\n\n", k, cont);
        
        scanf("%d", &m);
        k++;
    }
    
    return 0;
}
